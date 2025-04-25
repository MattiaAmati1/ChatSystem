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

void User::createChat(const std::string& receiverName) const {

    if(!UserList::userExists(receiverName))
        return;

    chatRegister->createChat(this -> username, receiverName);
}

void User::sendMessage(const std::string &receiverName, const std::string &messageText) const {

    if(!UserList::userExists(receiverName))
        return;

    const Message msg(messageText, this -> username);
    chatRegister->addMessage(this -> username, receiverName, msg);
}

