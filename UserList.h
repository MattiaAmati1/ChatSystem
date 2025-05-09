#ifndef USERLIST_H
#define USERLIST_H
#include <list>
#include <string>

class User;

inline std::list<User> globalUserList;

class UserList{ //handles functions needed to get User objects from their usernames

    public:
        UserList() = default;

        static void addUser(const User& user);
        static User getUserByName(const std::string &name);
        [[nodiscard]] static bool userExists(const std::string &name);
};

#endif //USERLIST_H
