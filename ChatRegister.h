#ifndef CHATREGISTER_H
#define CHATREGISTER_H
#include <iostream>
#include <vector>
#include "Chat.h"


class ChatRegister {

    public:
        ChatRegister();

        static void addChat(const Chat &c) {

            for(auto chat : chats) {
                if(chat.getID() == c.getID()) {
                    std::cout << "chat " << chat.getID() << " already exists" << std::endl;
                    return;
                }
            }
            chats.push_back(c);

        }

        ~ChatRegister() {
            chats.clear();
            totalUsers.clear();
        }

    private:
        static std::vector<Chat> chats;
        static std::vector<User> totalUsers;
};



#endif //CHATREGISTER_H
