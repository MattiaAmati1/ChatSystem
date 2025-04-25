#ifndef CHATREGISTER_H
#define CHATREGISTER_H
#include <list>
#include "Chat.h"


class ChatRegister {

    public:
        void createChat(const std::string& authorName, const std::string& receiverName, const std::string& chatName);
        void addMessage(const std::string& authorName, const std::string& receiverName, const Message& message);
        [[nodiscard]] bool containsChatWithUsers(const std::string& authorName, const std::string& receiverName) const;
        Chat& getChatWithUsers(const std::string& authorName, const std::string& receiverName);

    private:

        std::list<Chat> chatList;

};


#endif //CHATREGISTER_H
