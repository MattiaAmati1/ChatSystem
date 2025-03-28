#ifndef USER_H
#define USER_H

#include <string>
#include <list>
#include "Message.h"
#include "observer/Subject.h"

/*
 Every possible action is called by an user first,
 which notifies the corresponding method in the other classes.

 */

class User : public Subject{

    public:

        void subscribe(Observer *o) override{
            observers.push_back(o);
        }

        void unsubscribe(Observer* o) override{
            observers.remove(o);
        }

        void notify(UpdateType type) override{
            for(auto observer : observers)
                observer -> update(type);
        }

        explicit User(const std::string &username) : username(username) {}

        const std::string &getUsername() const { return username; }

        //users send messages in existing chats

        void sendMessage(const User &receiver, const std::string& textMessage) {

            notify(UpdateType::MESSAGE_SENT);

        }

        //users create brand-new chats or groups




        virtual ~User() = default;

        bool operator==(const User &right){
            return this -> username == right.username;
        }

    private:
        std::string username;
        std::list<Observer*> observers;

};

#endif //USER_H
