#ifndef ENCRYPTEDMESSAGE_H
#define ENCRYPTEDMESSAGE_H

#include "message.h"

#include <string>

enum SignatureState {
    NO_SIGNATURE,
    VALID,
    INVALID
};

class EncryptedMessage : public Message
{
public:
    EncryptedMessage();
    EncryptedMessage(std::string messageText);

    std::string    decrypt();
    SignatureState checkSignature();
};

#endif // ENCRYPTEDMESSAGE_H
