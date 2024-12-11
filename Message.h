#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include "User.h"


class Message {

    public:
        Message(const std::string &msg, const User& sender, const User& receiver)
                    : text(msg), sender(sender), receiver(receiver) {}

    private:
        std::string text;
        User sender;
        User receiver;

};



#endif //MESSAGE_H
