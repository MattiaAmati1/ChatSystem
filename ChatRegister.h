#ifndef CHATREGISTER_H
#define CHATREGISTER_H

#include "Chat.h"
#include "User.h"
#include "observer/Observer.h"

class ChatRegister final : public Observer{

    public:
        ChatRegister() = default;

        void attach() override {
            for(const auto subject : subjects)
                subject -> subscribe(this);
        }

        void detach() override {
            for(const auto subject : subjects)
                subject ->unsubscribe(this);
        }

        void update(const UpdateType type) override{}

        void update(const UpdateType type, const User author, const User receiver, const int id) override {
            switch(type) {
                case UpdateType::CHAT_CREATED:
                    createChat(type, author, receiver, id);
                    break;

                default:
                    break;
            }
        }

        void update(UpdateType type, User author, User receiver, Message textMessage) override{
            for(auto chat : chats)
                if((chat.getFirstUser() == author || chat.getFirstUser() == receiver) &&
                   (chat.getSecondUser() == author || chat.getSecondUser() == receiver ) ) {
                    chat.addMessage(textMessage);
                    return;
                }
        }

        std::list<Chat> getChatList() { return chats; }
        ~ChatRegister() override = default;

    private:
        std::list<User*> subjects;
        std::list<Chat> chats;

        void createChat(const UpdateType type, const User author, const User receiver, const int id) {
            const Chat chat(author, receiver, id);
            chats.push_back(chat);
        }
};




#endif //CHATREGISTER_H
