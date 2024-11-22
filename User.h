#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include "Chat.h"

class User {

    public:
        explicit User(const std::string &username = "_") : username(username) {
            activeChats.clear();
        }

    ~User() = default;

    private:
        std::string username;
        std::vector<Chat> activeChats;

};

#endif //USER_H
