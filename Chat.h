#ifndef CHAT_H
#define CHAT_H

#include "List.h"
#include "Message.h"
#include "User.h"


class Chat {

    public:

        Chat(const User& firstUser, const User& secondUser, int id, const std::string& name = "Unnamed Chat")
            : firstUser(firstUser), secondUser(secondUser), id(id), name(name){}

        const int & getID() const { return id; }

        const bool operator==(const Chat &right) const { return this -> id == right.id; }

        ~Chat() = default;
    private:


        std::list<Message> chatMessages;
        User firstUser;
        User secondUser;
        int id;
        std::string name;
};



#endif //CHAT_H