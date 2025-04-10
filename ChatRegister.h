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

        void update(const UpdateType type, User* author, User* receiver, const int id) override {
            switch(type) {
                case UpdateType::CHAT_CREATED:
                    createChat(type, author, receiver, id);
                    break;
                default:
                    break;
            }
        }

        void update(const UpdateType type, const User* author, const User* receiver, const Message &textMessage) override{
            switch(type) {
                case UpdateType::MESSAGE_SENT:
                    for(const auto &chat : chats)
                        if(chat -> getFirstUser() == author && chat -> getSecondUser() == receiver ||
                           chat -> getFirstUser() == author && chat -> getFirstUser() == receiver)
                            chat -> addMessage(textMessage);
                break;
                default:
                    break;
            }
        }

        [[nodiscard]] std::list<Chat*> getChatList() const { return chats; }
        ~ChatRegister() override = default;

        Chat* getChatWithUsers(const User* author, const User* receiver) const {
            for(const auto &chat : chats)
                if(chat -> getFirstUser() == author && chat -> getSecondUser() == receiver ||
                    chat -> getFirstUser() == receiver && chat -> getFirstUser() == author)
                    return chat;

            return nullptr;
        }

    private:
        std::list<User*> subjects;
        std::list<Chat*> chats;

        void createChat(const UpdateType type, User* author, User* receiver, const int id) {
            Chat* chat = new Chat(author, receiver, id);
            chats.push_back(chat);
        }
};




#endif //CHATREGISTER_H
