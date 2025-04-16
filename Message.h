#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <ctime>

/*
 A Message object is used to memorize information relative to a message
 (such as when it was sent) and to support implementation of messages
 with different types of information (images, media...)
 */

class Message {

    public:
        Message(std::string text, std::string author) : text(std::move(text)),
                                                        authorName (std::move(author)), read(false){
            timestamp = time(nullptr); //sets timestamp to the date and time the object is instantiated
        }

        [[nodiscard]] std::string getAuthor() const { return authorName; }

        [[nodiscard]] std::string toString() const { return authorName + "\n" + text + "\n" + std::to_string(timestamp); }

        bool operator==(const Message &right) const {
            return text == right.text && authorName == right.authorName && timestamp == right.timestamp;
        }

    private:
        std::string text;
        std::string authorName;
        time_t timestamp;
        bool read;
};



#endif //MESSAGE_H
