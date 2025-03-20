#ifndef CHAT_H
#define CHAT_H
#include <vector>
#include "ChatRegister.h"
#include "Message.h"
#include "User.h"

class Chat {

    public:

        explicit Chat(const int &id) : id(id){
            users.clear();
            membersAmount = 0;
            group = false;
        }

        Chat(const std::list<User> &users, const int &id) : users(users), id(id) {
            if(this -> users.size() > 2)
                group = true;
            else
                group = false;

            membersAmount = this -> users.size();
            ChatRegister::addChat(*this);
        }

        Chat(const User& firstUser, const User& secondUser, const int &id) : id(id) {
            users.push_back(firstUser);
            users.push_back(secondUser);

            group = false;
            membersAmount = users.size();
            ChatRegister::addChat(*this);
        }

        void addMessage(const Message &message) {
            chatMessages.push_back(message);
            //will have to notify other user(s)
        }

        void addMember(const User &user) {

            for(const auto& u : users) {
                if(u.getUsername() == user.getUsername())
                    return;
            }

            group = true;
            users.push_back(user);
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

        const std::list<User> & getUsers() const { return users; }

        ~Chat() {
            ChatRegister::removeChat(*this);
            chatMessages.clear();
        }

    private:
        std::list<User> users;
        std::list<Message> chatMessages;
        bool group;
        int membersAmount;
        int id;
        std::string name;

};

#endif //CHAT_H
