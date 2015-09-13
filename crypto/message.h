#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message
{
public:
    Message();
    Message(std::string messageText);

    std::string getMessage();
    void        setMessage(std::string text);

private:
    std::string messageText;
};

#endif // MESSAGE_H
