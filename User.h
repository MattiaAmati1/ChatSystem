#ifndef USER_H
#define USER_H

#include <string>
#include <utility>

#include "ChatRegister.h"


class User {

    public:

        User(std::string name, ChatRegister* r) : username(std::move(name)), chatRegister(r) {
            chatRegister -> addUser(this);
        }

        [[nodiscard]] const std::string &getUsername() const { return username; }

        void createChat(User *receiver);
        void sendMessage(const User& receiver, const std::string& messageText);


        bool operator==(const User &right) const { return this -> username == right.username; }
        ~User() = default;

    private:
        std::string username;
        ChatRegister* chatRegister;

};


#endif //USER_H
