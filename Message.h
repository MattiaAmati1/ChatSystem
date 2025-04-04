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
        Message(const std::string &text, const std::string &author) : text(text), authorName (author) {}

        std::string getAuthor() const { return authorName; }

    private:
        std::string text;
        std::string authorName;
        //date and time...


};



#endif //MESSAGE_H
