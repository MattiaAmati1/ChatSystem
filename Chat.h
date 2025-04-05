#ifndef CHAT_H
#define CHAT_H

#include <utility>
#include "Message.h"
#include "User.h"

class Chat{

    public:

        Chat(User* firstUser, User* secondUser, const int id, std::string  name = "Unnamed Chat")
            : firstUser(firstUser), secondUser(secondUser), id(id), name(std::move(name)){}

        [[nodiscard]] const int & getID() const { return id; } //adds a warning if the method is called bypassing the return value
        [[nodiscard]] const User* getFirstUser() const { return firstUser; }
        [[nodiscard]] const User *getSecondUser() const { return secondUser; }
        bool operator==(const Chat &right) const { return this -> id == right.id; }

        void addMessage(const Message& msg) {

            chatMessages.push_back(msg);
            if(msg.getAuthor() == firstUser -> getUsername())
                secondUser -> messageReceived();
            else
                firstUser -> messageReceived();

        }

        [[nodiscard]] Message getLatestMessage() const { return chatMessages.back(); }

        ~Chat() = default;

    private:
        std::list<Message> chatMessages;
        User* firstUser;
        User* secondUser;
        int id;
        std::string name;
};



#endif //CHAT_H