#ifndef CHATREGISTER_H
#define CHATREGISTER_H

#include "Chat.h"
#include "List.h"
#include "User.h"

class ChatRegister : public Observer{

public:
    ChatRegister() = default;

    void attach() override { subject ->subscribe(this); }
    void detach() override { subject ->unsubscribe(this); }
    void update(UpdateType type){
        switch(type){

            case UpdateType::CHAT_CREATED:
                break;
            case UpdateType::MESSAGE_SENT:
                break;
            case UpdateType::MEMBER_ADDED:
                break;
            case UpdateType::MEMBER_REMOVED:
                break;
            case UpdateType::DEFAULT:
                break;
        }
    }

    static void addChat(const Chat &c) {}
    static bool isUserInChat (const Chat &c, const User &user) { return c.getUserList().contains(user); }

    static void removeChat(const Chat &c) {
        chats.remove(c);
    }

    ~ChatRegister() {
        chats.clear();
    }

private:
    static List<Chat> chats;
    Chat * subject;
};




#endif //CHATREGISTER_H
