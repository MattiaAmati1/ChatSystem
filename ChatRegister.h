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

        static bool isUserInChat (const Chat &c, const User &user) {
            for(const auto& chat : chats) {
                if(chat.getID() == c.getID())
                    for(const auto& u : chat.getUsers())
                        if(u.getUsername() == user.getUsername())
                            return true;
            }

            return false;
        }

        static void removeChat(const Chat &c) {
            chats.remove(c);
        }

        ~ChatRegister() {
            chats.clear();
        }

    private:
        static std::list<Chat> chats;
};



#endif //CHATREGISTER_H
