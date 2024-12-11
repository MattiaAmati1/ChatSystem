#ifndef CHAT_H
#define CHAT_H
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
        }

        Chat(const User& firstUser, const User& secondUser) {
            users.push_back(firstUser);
            users.push_back(secondUser);

            isGroup = false;
            membersAmount = users.size();
        }

        const int & getID() const { return id; }

        ~Chat() = default;

    private:
        std::vector<User> users;
        std::vector<Message> chatMessages;
        bool isGroup;
        int membersAmount;
        int id;
        std::string name;

};

#endif //CHAT_H
