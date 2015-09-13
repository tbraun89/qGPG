#include "plainmessage.h"

#include <cstring>
#include <sstream>

#define BUFFER_SIZE 64

PlainMessage::PlainMessage() : Message() {
}

PlainMessage::PlainMessage(std::string messageText) : Message(messageText) {
}

std::string PlainMessage::encrypt(std::string recipient, std::string signer) {
    std::string temp = messageText;
    std::string result;

    messageText = sign(signer);
    result      = encrypt(recipient);
    messageText = temp;

    return result;
}

std::string PlainMessage::encrypt(std::string recipient) {
    gpgme_check_version(NULL);

    std::stringstream result;
    gpgme_ctx_t       ctx;
    gpgme_key_t       key;
    gpgme_error_t     err = gpgme_new(&ctx);

    if (!err) {
        gpgme_key_t            publicKey[2] = {NULL, NULL};
        gpgme_data_t           plainText;
        gpgme_data_t           encryptedText;
        gpgme_encrypt_result_t encryptedResult;
        ssize_t                readBytes;
        char buffer[BUFFER_SIZE];

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
            for (size_t i = 0; i < readBytes; i++)
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
    // TODO implement function
    return messageText;
}
