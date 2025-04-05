#ifndef USER_H
#define USER_H

#include <string>
#include <list>

#include "observer/Subject.h"

/*
 Every possible action is called by a user first,
 which notifies the corresponding method in the other classes.
 */

class User final : public Subject{

    public:

        User(const std::string &name, Observer* reg) : username(name) {
            this -> User::subscribe(reg);
            unreadMessages = 0;
        }

        void subscribe(Observer *o) override{
            observers.push_back(o);
        }

        void unsubscribe(Observer* o) override{
            observers.remove(o);
        }

        void notify(const UpdateType type) override{
            for(const auto observer : observers)
                observer -> update(type);
        }

        void notify(const UpdateType type, User* author, User* receiver, const int id) override {
            for(const auto observer : observers)
                observer -> update(type, author, receiver, id);
        }

        void notify(const UpdateType type, User* author, User* receiver, const Message textMessage) override{
            for(const auto observer : observers)
                observer -> update(type, author, receiver, textMessage);
        }

        //users send messages in existing chats

        void sendMessage(User *receiver, const Message &textMessage) {

            notify(UpdateType::MESSAGE_SENT, this, receiver, textMessage);
        }

        //users create brand-new chats or groups

        void createChat(User* otherUser, const int &id) {

            notify(UpdateType::CHAT_CREATED, this, otherUser, id);
        }

        const std::string &getUsername() const { return username; }
        const int getUnreadMessages() const { return unreadMessages; }

        bool operator==(const User &right) const {
            return this -> username == right.username;
        }

        ~User() override = default;

        void messageReceived(){
            unreadMessages++;
        }

    private:
        std::string username;
        std::list<Observer*> observers;
        int unreadMessages;

};

#endif //USER_H
