#ifndef CHAT_H
#define CHAT_H

#include "List.h"
#include "Message.h"
#include "User.h"


class Chat{

    public:

        Chat(const User& firstUser, const User& secondUser, int id, const std::string& name = "Unnamed Chat")
            : firstUser(firstUser), secondUser(secondUser), id(id), name(name){}

        const int & getID() const { return id; }
        const User &getFirstUser() const { return firstUser; }
        const User &getSecondUser() const { return secondUser; }
        const bool operator==(const Chat &right) const { return this -> id == right.id; }

        void addMessage(const Message& msg) {

            chatMessages.push_back(msg);
            if(msg.getAuthor() == firstUser.getUsername())
                secondUser.messageReceived();
            else
                firstUser.messageReceived();

        }

        ~Chat() = default;
    private:
        std::list<Message> chatMessages;
        User firstUser;
        User secondUser;
        std::list<Observer*> observers;
        int id;
        std::string name;
};



#endif //CHAT_H