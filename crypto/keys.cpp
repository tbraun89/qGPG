#include "keys.h"

#include <gpgme.h>
#include <sstream>

std::list<std::pair<std::string, std::string> > Keys::getKeys(int gpgme_type) {
    std::list<std::pair<std::string, std::string> > result;

    gpgme_check_version(NULL);

    gpgme_ctx_t   ctx;
    gpgme_key_t   key;
    gpgme_error_t err = gpgme_new(&ctx);

    if (!err) {
        err = gpgme_op_keylist_start(ctx, "", gpgme_type);

        while (!err) {
            err = gpgme_op_keylist_next(ctx, &key);

            if (err)
                break;

            std::pair<std::string, std::string> currentElement;
            std::ostringstream                  value;

            value << key->uids->name << " <" << key->uids->email << ">";

            currentElement.first  = key->subkeys->keyid;
            currentElement.second = value.str();

            result.push_back(currentElement);
        }
    }

    if (gpg_err_code(err) != GPG_ERR_EOF)
        throw gpgme_strerror((err));

    return result;
}

std::list<std::pair<std::string, std::string> > Keys::getPublicKeys() {
    return getKeys(0);
}

std::list<std::pair<std::string, std::string> > Keys::getSecretKeys() {
    return getKeys(1);
}
