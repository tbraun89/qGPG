#include "plainmessage.h"

#include <gpgme.h>

PlainMessage::PlainMessage() : Message() {
}

PlainMessage::PlainMessage(std::string messageText) : Message(messageText) {
}

std::string PlainMessage::encrypt(std::string recipient) {
    // TODO implement function
}

std::string PlainMessage::sign(std::string signer) {
    // TODO implement function
}
