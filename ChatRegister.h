#ifndef CHATREGISTER_H
#define CHATREGISTER_H
#include <list>
#include "Chat.h"

class User;

class ChatRegister {

    public:
        void createChat(User *author, User *receiver);
        void addMessage(const User *author, const User *receiver, const Message& msg) const;
        [[nodiscard]] std::list<User*> globalUserList() const { return userList; }
        void addUser(User *user);

    private:
        std::list<Chat*> chatList;
        std::list<User*> userList;
};

#endif //CHATREGISTER_H
