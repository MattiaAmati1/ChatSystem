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
        Message(const std::string &text, const std::string &author) : text(text), authorName (author) {
            timestamp = time(nullptr);
        }

        std::string getAuthor() const { return authorName; }

        void show() const {
            std::cout << text << std::endl;
            std::cout << "By " << authorName << std::endl;
            std::cout << "Sent on: " << ctime(&timestamp) << std::endl;
        }

        bool operator==(const Message &right) const {
            return text == right.text && authorName == right.authorName && timestamp == right.timestamp;
        }

    private:
        std::string text;
        std::string authorName;
        time_t timestamp;

};



#endif //MESSAGE_H
