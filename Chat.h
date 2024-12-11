#ifndef CHAT_H
#define CHAT_H
#include <vector>
#include "ChatRegister.h"
#include "Message.h"
#include "User.h"


class Chat {

    public:
        Chat(const std::vector<User> &users, const int &id) : users(users), id(id) {
            if(this -> users.size() > 2)
                isGroup = true;
            else
                isGroup = false;

            membersAmount = this -> users.size();
            ChatRegister::addChat(*this);
        }

        Chat(const User& firstUser, const User& secondUser, const int &id) : id(id) {
            users.push_back(firstUser);
            users.push_back(secondUser);

            isGroup = false;
            membersAmount = users.size();
            ChatRegister::addChat(*this);
        }

        void addMessage(const Message &message) {
            chatMessages.push_back(message);
            //will have to notify other user(s)
        }

        const int & getID() const { return id; }

        const std::vector<User> & getUsers() const { return users; }

        ~Chat() {
            ChatRegister::removeChat(*this);
        }

    private:
        std::vector<User> users;
        std::vector<Message> chatMessages;
        bool isGroup;
        int membersAmount;
        int id;
        std::string name;

};

#endif //CHAT_H
