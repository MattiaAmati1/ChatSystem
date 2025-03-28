#ifndef CHAT_H
#define CHAT_H

#include "List.h"
#include "Message.h"
#include "User.h"

//A Chat is both an observer for a User subject, to be notified when a User interacts with the system
//and a subject for a ChatRegister observer which has to keep track of all the created chats and their members
class Chat : public Observer, Subject{

    public:

        void attach() override{ subject -> subscribe(this); }
        void detach() override{ subject -> unsubscribe(this); }
        void subscribe(Observer* o) override { observers.push_back(o); }
        void unsubscribe(Observer* o) override { observers.remove(o); }

        void notify(UpdateType type) override {
            for(auto observer : observers)
                observer ->update(type);
        }

        void update(UpdateType type) override{
            //will receive different types of update commands
            //and call the corresponding class method
            //based on the action performed by the user
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

        const bool & isGroup() const { return group; }

        const int & getID() const { return id; }

        List<User> getUserList() const { return users; }

        const int getMembersNumber() const { return  membersAmount; }

        const bool operator==(const Chat &right) const { return this -> id == right.id; }

        ~Chat() {
            //ChatRegister::removeChat(*this);
            chatMessages.clear();
            subject -> unsubscribe(this);
        }

    private:

        List<User> users;
        List<Message> chatMessages;
        bool group;
        int membersAmount;
        int id;
        std::string name;
        User * subject;
        std::list<Observer*> observers;

};



#endif //CHAT_H