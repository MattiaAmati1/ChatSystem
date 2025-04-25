#include "User.h"
#include <stdexcept>

User UserList::getUserByName(const std::string &name) {

    for(const auto& user : globalUserList)
        if(user.getUsername() == name)
            return user;

    throw std::invalid_argument("User does not exist");
}

bool UserList::userExists(const std::string &name) {

    for(const auto& user : globalUserList)
        if(user.getUsername() == name)
            return true;

    return false;
}

void User::createChat(const std::string& receiverName, const std::string& chatName) const {

    if(!UserList::userExists(receiverName))
        return;

    chatRegister->createChat(this -> username, receiverName, chatName);
}

void User::sendMessage(const std::string &receiverName, const std::string &messageText) const {

    if(!UserList::userExists(receiverName))
        return;

    const Message msg(this -> username, messageText);
    chatRegister->addMessage(this -> username, receiverName, msg);
}

void User::sendMessage(const std::string &receiverName, const Message& msg) const {

    if(!UserList::userExists(receiverName))
        return;

    chatRegister->addMessage(this -> username, receiverName, msg);
}

void User::setMessageToUnread(const std::string &authorName, int index) const {

    if(!UserList::userExists(authorName))
        return;

    if(!chatRegister -> containsChatWithUsers(this -> username, authorName))
        return;

    if(chatRegister -> getChatWithUsers(this -> username, authorName).getMessageAtPosition(index).getAuthorName() == authorName)
        chatRegister -> getChatWithUsers(this -> username, authorName).getMessageAtPosition(index).setRead(false);
}

std::string User::readUnreadMessage(const std::string &authorName, const int index) const {

    if(!UserList::userExists(authorName))
        return "";

    if(!chatRegister -> containsChatWithUsers(this -> username, authorName))
        return "";

    Message& tmp = chatRegister -> getChatWithUsers(this -> username, authorName).getMessageAtPosition(index);
    if(tmp.getAuthorName() != authorName)
        return "";

    if(tmp.isRead())
        return "";


    tmp.setRead(true);
    return tmp.toString();
}

std::string User::readUnreadMessagesWithWord(const std::string &authorName, const std::string &word) const {

    if(!UserList::userExists(authorName))
        return "";

    if(!chatRegister -> containsChatWithUsers(this -> username, authorName))
        return "";

    Chat& tmp = chatRegister -> getChatWithUsers(this -> username, authorName);
    std::string messages;

    for(auto msg : tmp.getMessagesWithWord(word))
        if(!msg.isRead()) {
            messages += msg.toString();
            messages += "\n";
            msg.setRead(true);
        }

    return messages;
}