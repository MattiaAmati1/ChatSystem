#include "User.h"
#include "ChatRegister.h"

void User::createChat(User *receiver) {

    bool flag = false;
    for(const auto& user : chatRegister -> globalUserList())
        if(user == *receiver)
            flag = true;

    if(flag)
        return;

    chatRegister -> createChat(this, receiver);
}

void User::sendMessage(const User &receiver, const std::string& messageText) {
    const Message msg(username, messageText);
    chatRegister -> addMessage(this, &receiver, msg);
}

