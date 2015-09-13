#include "plainmessage.h"

#include <cstring>
#include <sstream>

#define BUFFER_SIZE 64

PlainMessage::PlainMessage() : Message() {
}

PlainMessage::PlainMessage(std::string messageText) : Message(messageText) {
}

// TODO refactor encrypt, and sign functions replace deprecated functions

std::string PlainMessage::encrypt(std::string recipient, std::string signer) {
    gpgme_check_version(NULL);

    std::stringstream result;
    gpgme_ctx_t       ctx;
    gpgme_error_t     err = gpgme_new(&ctx);

    if (!err) {
        gpgme_key_t            publicKey[2] = {NULL, NULL};
        gpgme_key_t            signingKey;
        gpgme_data_t           plainText;
        gpgme_data_t           encryptedText;
        gpgme_encrypt_result_t encryptedResult;
        ssize_t                readBytes;
        char                   buffer[BUFFER_SIZE];

        gpgme_set_armor(ctx, 1);
        gpgme_data_new(&encryptedText);
        gpgme_signers_clear(ctx);

        gpgme_op_keylist_start(ctx, recipient.c_str(), 0);
        gpgme_op_keylist_next(ctx, &publicKey[0]);
        gpgme_op_keylist_end(ctx);

        gpgme_op_keylist_start(ctx, signer.c_str(), 1);
        gpgme_op_keylist_next(ctx, &signingKey);
        gpgme_op_keylist_end(ctx);

        gpgme_signers_add(ctx, signingKey);

        gpgme_data_new_from_mem(&plainText, messageText.c_str(), strlen(messageText.c_str()), 1);
        gpgme_op_encrypt_sign(ctx, publicKey, GPGME_ENCRYPT_ALWAYS_TRUST, plainText, encryptedText);
        encryptedResult = gpgme_op_encrypt_result(ctx);

        gpgme_data_rewind(encryptedText);
        readBytes = gpgme_data_read(encryptedText, buffer, BUFFER_SIZE);

        while(readBytes > 0) {
            for (ssize_t i = 0; i < readBytes; i++)
                result << buffer[i];

            readBytes = gpgme_data_read(encryptedText, buffer, BUFFER_SIZE);
        }
    }

    // TODO implement error handling
    //if (gpg_err_code(err) != GPG_ERR_EOF)
    //    throw gpgme_strerror((err));

    return result.str();
}

std::string PlainMessage::encrypt(std::string recipient) {
    gpgme_check_version(NULL);

    std::stringstream result;
    gpgme_ctx_t       ctx;
    gpgme_error_t     err = gpgme_new(&ctx);

    if (!err) {
        gpgme_key_t            publicKey[2] = {NULL, NULL};
        gpgme_data_t           plainText;
        gpgme_data_t           encryptedText;
        gpgme_encrypt_result_t encryptedResult;
        ssize_t                readBytes;
        char                   buffer[BUFFER_SIZE];

        gpgme_set_armor(ctx, 1);
        gpgme_data_new(&encryptedText);

        gpgme_op_keylist_start(ctx, recipient.c_str(), 0);
        gpgme_op_keylist_next(ctx, &publicKey[0]);
        gpgme_op_keylist_end(ctx);

        gpgme_data_new_from_mem(&plainText, messageText.c_str(), strlen(messageText.c_str()), 1);
        gpgme_op_encrypt(ctx, publicKey, GPGME_ENCRYPT_ALWAYS_TRUST, plainText, encryptedText);
        encryptedResult = gpgme_op_encrypt_result(ctx);

        gpgme_data_rewind(encryptedText);
        readBytes = gpgme_data_read(encryptedText, buffer, BUFFER_SIZE);

        while(readBytes > 0) {
            for (ssize_t i = 0; i < readBytes; i++)
                result << buffer[i];

            readBytes = gpgme_data_read(encryptedText, buffer, BUFFER_SIZE);
        }
    }

    // TODO implement error handling
    //if (gpg_err_code(err) != GPG_ERR_EOF)
    //    throw gpgme_strerror((err));

    return result.str();
}

std::string PlainMessage::sign(std::string signer) {
    gpgme_check_version(NULL);

    std::stringstream result;
    gpgme_ctx_t       ctx;
    gpgme_error_t     err = gpgme_new(&ctx);

    if (!err) {
        gpgme_key_t       signingKey;
        gpgme_data_t        plainText;
        gpgme_data_t        signedText;
        gpgme_sign_result_t signedResult;
        ssize_t             readBytes;
        char                buffer[BUFFER_SIZE];

        gpgme_set_armor(ctx, 1);
        gpgme_data_new(&signedText);
        gpgme_signers_clear(ctx);

        gpgme_op_keylist_start(ctx, signer.c_str(), 1);
        gpgme_op_keylist_next(ctx, &signingKey);
        gpgme_op_keylist_end(ctx);

        gpgme_signers_add(ctx, signingKey);

        gpgme_data_new_from_mem(&plainText, messageText.c_str(), strlen(messageText.c_str()), 1);
        gpgme_op_sign(ctx, plainText, signedText, GPGME_SIG_MODE_NORMAL);
        signedResult = gpgme_op_sign_result(ctx);

        gpgme_data_rewind(signedText);
        readBytes = gpgme_data_read(signedText, buffer, BUFFER_SIZE);

        while(readBytes > 0) {
            for (ssize_t i = 0; i < readBytes; i++)
                result << buffer[i];

            readBytes = gpgme_data_read(signedText, buffer, BUFFER_SIZE);
        }
    }

    // TODO implement error handling
    //if (gpg_err_code(err) != GPG_ERR_EOF)
    //    throw gpgme_strerror((err));

    return result.str();
}
