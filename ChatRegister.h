#ifndef CHATREGISTER_H
#define CHATREGISTER_H
#include <iostream>
#include <list>
#include "Chat.h"


class Chat;

class ChatRegister {

    public:
        ChatRegister();

        static void addChat(const Chat &c) {

            for(const auto& chat : chats) {
                if(chat.getID() == c.getID()) {
                    std::cout << "chat " << chat.getID() << " already exists" << std::endl;
                    return;
                }
            }
            chats.push_back(c);

        }

        static void removeChat(const Chat &c) {
            chats.remove(c);
        }

        ~ChatRegister() {
            chats.clear();
            totalUsers.clear();
        }

    private:
        static std::list<Chat> chats;
        static std::list<User> totalUsers;
};



#endif //CHATREGISTER_H
