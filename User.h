#ifndef USER_H
#define USER_H

#include <string>
#include <utility>
#include "ChatRegister.h"
#include "UserList.h"


class User {

    public:

        explicit User(std::string name, ChatRegister* reg)
                    : username(std::move(name)), chatRegister(reg) {

            UserList::addUser(*this);
        }

        [[nodiscard]] const std::string &getUsername() const { return username; }

        void createChat(const std::string& receiverName) const;
        void sendMessage(const std::string& receiverName, const std::string& messageText) const;


        bool operator==(const User &right) const { return this -> username == right.username; }
        ~User() = default;

    private:
        std::string username;
        ChatRegister* chatRegister; //if this is not a pointer copies of the register are made
};

#endif //USER_H
