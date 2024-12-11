#ifndef USER_H
#define USER_H
#include <string>

#include "ChatRegister.h"
#include "ChatRegister.h"


class User {

    public:
        explicit User(const std::string &username) : username(username) {}

        const std::string &getUsername() const { return username; }

        ~User() = default;

    private:
        std::string username;

};

#endif //USER_H
