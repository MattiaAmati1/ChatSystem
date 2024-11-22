#ifndef CHATREGISTER_H
#define CHATREGISTER_H
#include <vector>

#include "Chat.h"


class ChatRegister {

    public:
        ChatRegister();

        ~ChatRegister() { chats.clear(); }
    private:
        std::vector<Chat> chats;
};



#endif //CHATREGISTER_H
