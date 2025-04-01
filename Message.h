#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>

/*

 A Message object is used to memorize information relative to a message
 (such as when it was sent) and to support implementation of messages
 with different types of information (images, media...)

 */

class Message {

    public:
        explicit Message(const std::string &text) : text(text) {}
    private:
        std::string text;
        //date and time...


};



#endif //MESSAGE_H
