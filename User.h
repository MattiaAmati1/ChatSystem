#ifndef USER_H
#define USER_H

#include <string>
#include "Chat.h"
#include "Message.h"
#include "ChatRegister.h"



class User {

    public:
        explicit User(const std::string &username) : username(username) {}

        const std::string &getUsername() const { return username; }

        //users send messages in existing chats

        void sendMessage(Chat &chat, const Message &message) {

            if(ChatRegister::isUserInChat(chat, this)) {
                chat.addMessage(message);
            }

            //will have to notify the chat
        }

        //users create brand-new chats or groups

        ~User() = default;

    private:
        std::string username;

};

#endif //USER_H
