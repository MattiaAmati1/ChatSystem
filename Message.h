#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include "User.h"


class Message {

    public:
        explicit Message(const std::string &text) : text(text) {}
    private:
        std::string text;


};



#endif //MESSAGE_H
