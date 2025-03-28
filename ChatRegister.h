#ifndef CHATREGISTER_H
#define CHATREGISTER_H

#include "Chat.h"
#include "List.h"
#include "User.h"

class ChatRegister : public Observer{

public:
    ChatRegister() = default;

    static void addChat(const Chat &c) {
        if(chats.contains(c))
            return;

        chats.add(c);
    }
    static bool isUserInChat (const Chat &c, const User &user) { return c.getUserList().contains(user); }

    static void removeChat(const Chat &c) {
        chats.remove(c);
    }

    ~ChatRegister() {
        chats.clear();
    }

private:
    static List<Chat> chats;
};




#endif //CHATREGISTER_H
