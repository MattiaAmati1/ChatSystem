#include <iostream>

#include "ChatRegister.h"
#include "User.h"

int main() {

    ChatRegister chatRegister;
    std::string data;

    std::cout << "Enter first username: ";
    getline(std::cin, data);

    const User firstUser(data, &chatRegister);

    //this control has to be done before User instantiation
    bool flag = false;
    do {
        std::cout << "Enter second username: ";
        getline(std::cin, data);
        if(data != firstUser.getUsername())
            flag = true;
        else {
            std::cout << "Name " << data << " already used" << std::endl;
            std::cin.clear();
        }
    } while (!flag);

    const User secondUser(data, &chatRegister);

    firstUser.createChat(secondUser.getUsername());
    if(chatRegister.containsChatWithUsers(firstUser.getUsername(), secondUser.getUsername()))
        std::cout << "Chat created" << std::endl;
    else
        return 0;

    std::cout << "Enter message to send from user " << firstUser.getUsername()  << " to " << secondUser.getUsername() << std::endl;
    getline(std::cin, data);
    firstUser.sendMessage(secondUser.getUsername(), data);

    std::cout << "Reading of the first message by the receiver: " << std::endl;
    std::cout << secondUser.readUnreadMessage(firstUser.getUsername(), 0) << std::endl;

    std::cout << "Enter a reply from " << secondUser.getUsername() << " to " << firstUser.getUsername() << std::endl;
    getline(std::cin, data);
    Message msg(secondUser.getUsername(), data);
    secondUser.sendMessage(firstUser.getUsername(), msg);

    std::cout << "Reading of the reply: " << std::endl;
    std::cout << firstUser.readUnreadMessage(secondUser.getUsername(), 1) << std::endl;

    std::cout << "Enter keyword: " << std::endl;
    getline(std::cin, data);
    std::cout << "Showing messages containing word " << data << std::endl;

    //if we know a chat is present in the register, getChatWithUsers() won't throw exceptions
    if(chatRegister.containsChatWithUsers(firstUser.getUsername(), secondUser.getUsername())) {
        for(const auto& message : chatRegister.getChatWithUsers(firstUser.getUsername(), secondUser.getUsername()).getMessagesWithWord(data))
            std::cout << message.toString() << std::endl;
    }
}


