#ifndef PLAINMESSAGE_H
#define PLAINMESSAGE_H

#include "message.h"

#include <string>

class PlainMessage : public Message
{
public:
    PlainMessage();
    PlainMessage(std::string messageText);

    std::string encrypt(std::string recipient, std::string signer);
    std::string encrypt(std::string recipient);
    std::string sign(std::string signer);
};

#endif // PLAINMESSAGE_H
