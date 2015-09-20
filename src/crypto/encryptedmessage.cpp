#include "encryptedmessage.h"

#include <gpgme.h>

EncryptedMessage::EncryptedMessage() : Message() {
}

EncryptedMessage::EncryptedMessage(std::string messageText) : Message(messageText) {
}

std::string EncryptedMessage::decrypt() {
    // TODO implement function
}

SignatureState EncryptedMessage::checkSignature() {
    // TODO implement function
}
