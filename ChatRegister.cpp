#include "User.h"

void ChatRegister::createChat(User *author, User *receiver) {

    for(const auto& chat :chatList)
        if(*chat->getFirstUser() == *author and *chat->getSecondUser() == *receiver or
           *chat->getFirstUser() == *receiver and *chat->getSecondUser() == *author) {
            Chat *newChat = new Chat(author, receiver);
            chatList.push_back(newChat);
        }

}

void ChatRegister::addMessage(const User *author, const User *receiver, const Message& msg) const {

    for(const auto& chat :chatList)
        if(*chat->getFirstUser() == *author and *chat->getSecondUser() == *receiver or
           *chat->getFirstUser() == *receiver and *chat->getSecondUser() == *author) {

            chat -> addMessage(msg);
        }
}

void ChatRegister::addUser(User *user) {
    userList.push_back(user);
}


