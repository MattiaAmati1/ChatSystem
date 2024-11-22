#ifndef CHAT_H
#define CHAT_H
#include "Message.h"
#include "User.h"


class Chat {

    public:
        explicit Chat(const std::vector<User> &users) : users(users) {
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

        ~Chat() = default;

    private:
        std::vector<User> users;
        std::vector<Message> chatMessages;
        bool isGroup;
        int membersAmount;

};

#endif //CHAT_H
