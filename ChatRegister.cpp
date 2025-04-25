#include "ChatRegister.h"
#include "User.h"

void ChatRegister::createChat(const std::string& authorName, const std::string& receiverName, const std::string& chatName) {

    if(containsChatWithUsers(authorName, receiverName))
        return; //if this chat already exists, it is not created

    Chat chat(authorName, receiverName, chatName);
    chatList.push_back(chat);
}

bool ChatRegister::containsChatWithUsers(const std::string &authorName, const std::string &receiverName) const {

    for(const auto& chat : chatList)
        if(chat.getFirstUserName() == authorName && chat.getSecondUserName() == receiverName ||
            chat.getFirstUserName() == receiverName && chat.getSecondUserName() == authorName)  //two chats are the same if they contain the same two users
            return true;

    return false;
}

Chat& ChatRegister::getChatWithUsers(const std::string& authorName, const std::string& receiverName) {

    for(auto& chat : chatList)
        if(chat.getFirstUserName() == authorName && chat.getSecondUserName() == receiverName ||
           chat.getFirstUserName() == receiverName && chat.getSecondUserName() == authorName)
            return chat;

    throw std::invalid_argument("A chat with these users does not exist");

}

void ChatRegister::addMessage(const std::string& authorName, const std::string& receiverName, const Message& message) {

    if(!containsChatWithUsers(authorName, receiverName))
        return; //if a chat between these users does not exist, messages cannot be sent

    //this gets called only if the chat exists because of the previous check
    //no need to try-catch
    getChatWithUsers(authorName, receiverName).addMessage(message);
}
