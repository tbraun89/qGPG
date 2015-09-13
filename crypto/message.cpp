#include "message.h"

Message::Message(std::string messageText) : messageText(messageText) {
}

Message::Message() : messageText("") {
}

std::string Message::getMessage() {
    return messageText;
}

void Message::setMessage(std::string text) {
    messageText = text;
}
