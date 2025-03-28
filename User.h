#ifndef USER_H
#define USER_H

#include <string>
#include <list>
#include "Message.h"
#include "observer/Subject.h"


class User : public Subject{

    public:

        void subscribe(Observer *o) override{
            observers.push_back(o);
        }

        void unsubscribe(Observer* o) override{
            observers.remove(o);
        }

        void notify() override{
            for(auto observer : observers)
                observer->update();
        }

        explicit User(const std::string &username) : username(username) {}

        const std::string &getUsername() const { return username; }

        //users send messages in existing chats

        void sendMessage(const User &receiver, const std::string& textMessage) {


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
