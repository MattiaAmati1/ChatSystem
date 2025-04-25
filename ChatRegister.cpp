#include "ChatRegister.h"
#include "User.h"

void ChatRegister::createChat(const std::string& authorName, const std::string& receiverName) {

    if(containsChatWithUsers(authorName, receiverName))
        return; //if this chat already exists, it is not created

    Chat chat(authorName, receiverName);
    chatList.push_back(chat);
}

bool ChatRegister::containsChatWithUsers(const std::string &authorName, const std::string &receiverName) const {

    for(const auto& chat : chatList)
        if(chat.getFirstUserName() == authorName && chat.getSecondUserName() == receiverName ||
            chat.getFirstUserName() == receiverName && chat.getSecondUserName() == authorName)  //two chats are the same if they contain the same two users
            return true;

    return false;
}


void ChatRegister::addMessage(const std::string& authorName, const std::string& receiverName, const Message& message) const {

    if(!UserList::userExists(authorName) || !UserList::userExists(receiverName))
        return; //both users need to exist

    if(!containsChatWithUsers(authorName, receiverName))
        return; //if a chat between these users does not exist, messages cannot be sent


    for(auto chat : chatList)
        if(chat.getFirstUserName() == authorName && chat.getSecondUserName() == receiverName ||
           chat.getFirstUserName() == receiverName && chat.getSecondUserName() == authorName) {
            chat.addMessage(message);
        }
}
