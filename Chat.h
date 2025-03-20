#ifndef CHAT_H
#define CHAT_H
#include "List.h"
#include "Message.h"
#include "User.h"

class ChatRegister;

class Chat {

    public:

        explicit Chat(const int &id) : id(id){
            users = List<User>();
            membersAmount = 0;
            group = false;
        }

        Chat(const List<User> &users, const int &id) : users(users), id(id) {
            if(this -> users.getSize() > 2)
                group = true;
            else
                group = false;

            membersAmount = this -> users.getSize();
            ChatRegister::addChat(*this);
        }

        Chat(const User& firstUser, const User& secondUser, const int &id) : id(id) {
            users.add(firstUser);
            users.add(secondUser);

            group = false;
            membersAmount = users.getSize();
            ChatRegister::addChat(*this);
        }

        void addMessage(const Message &message) {
            chatMessages.add(message);
            //will have to notify other user(s)
        }

        void addMember(const User &user) {

            if(users.contains(user))
                return;

            group = true;
            users.add(user);
            membersAmount ++;

        }

        void removeMember (const User &user) {

            if(!group) {
                std::cout << "you can't remove a member from a private chat" << std::endl;
                return;
            }

            if(!ChatRegister::isUserInChat(this, user))
                return;

            users.remove(user);
            membersAmount--;
            if(membersAmount <= 2)
                group = false;

        }

        const bool & isGroup() const { return group; }

        const int & getID() const { return id; }

        List<User> getUserList() const { return users; }

        const int getMembersNumber() const { return  membersAmount; }

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

};



#endif //CHAT_H