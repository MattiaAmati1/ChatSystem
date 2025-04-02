#ifndef USER_H
#define USER_H

#include <string>
#include <list>
#include <fstream>

#include "observer/Subject.h"


/*
 Every possible action is called by a user first,
 which notifies the corresponding method in the other classes.
 */

class User final : public Subject{

    public:

        User(const std::string &name, Observer* reg) : username(name) {
            this -> User::subscribe(reg);
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

        void notify(const UpdateType type, const User author, const User receiver, const int id) override {
            for(const auto observer : observers)
                observer -> update(type, author, receiver, id);
        }


        const std::string &getUsername() const { return username; }

        //users send messages in existing chats

        void sendMessage(const User &receiver, const std::string& textMessage) {


        }

        //users create brand-new chats or groups

        void createChat(const User &otherUser, const int &id) {

            notify(UpdateType::CHAT_CREATED, *this, otherUser, id);
        }

        ~User() override = default;

        bool operator==(const User &right) const {
            return this -> username == right.username;
        }

    private:
        std::string username;
        std::list<Observer*> observers;

};

#endif //USER_H
