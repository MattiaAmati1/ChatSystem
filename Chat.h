#ifndef CHAT_H
#define CHAT_H

#include <utility>
#include "List.h"
#include "Message.h"
#include "User.h"
#include "ChatRegister.h"


class Chat : public Observer{

    public:

        Chat(User& firstUser, User& secondUser, const Message &firstMessage, const int &id) : id(id), users(List<User>(firstUser)),
                                                                                            chatMessages(List<Message>(std::move(firstMessage))){


        }

        void attach() override{
            subject -> subscribe(this);
        }

        void detach() override{
            subject -> unsubscribe(this);
        }

        void update() override{
            //will receive different types of update commands
            //based on the action performed by the user
        }

        void addMessage(const Message &message) {
            chatMessages.add(message);
            //will have to notify other user(s)
        }

        void addMember(const User &user) {



        }

        void removeMember (const User &user) {

            if(!group) {
                std::cout << "you can't remove a member from a private chat" << std::endl;
                return;
            }

        }

        const bool & isGroup() const { return group; }

        const int & getID() const { return id; }

        List<User> getUserList() const { return users; }

        const int getMembersNumber() const { return  membersAmount; }

        const bool operator==(const Chat &right) const { return this -> id == right.id; }

        ~Chat() {
            ChatRegister::removeChat(*this);
            chatMessages.clear();
        }

    private:

        List<User> users;
        List<Message> chatMessages;
        bool group;
        int membersAmount;
        int id;
        std::string name;

        User * subject;

};



#endif //CHAT_H