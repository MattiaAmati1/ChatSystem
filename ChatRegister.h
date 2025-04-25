#ifndef CHATREGISTER_H
#define CHATREGISTER_H
#include <list>
#include "Chat.h"


class ChatRegister {

    public:
        void createChat(const std::string& authorName, const std::string& receiverName);
        void addMessage(const std::string& authorName, const std::string& receiverName, const Message& message) const;
        bool containsChatWithUsers(const std::string& authorName, const std::string& receiverName) const;

    private:

        std::list<Chat> chatList;

};


#endif //CHATREGISTER_H
