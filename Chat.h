#ifndef CHAT_H
#define CHAT_H

#include <utility>
#include <iostream>
#include <vector>
#include "Message.h"
#include "User.h"

class Chat{

    public:

        Chat(User* firstUser, User* secondUser, std::string  name = "Unnamed Chat")
            : firstUser(firstUser), secondUser(secondUser), name(std::move(name)){}

        //adds a warning if the method is called bypassing the return value
        [[nodiscard]] const User* getFirstUser() const { return firstUser; }
        [[nodiscard]] const User*getSecondUser() const { return secondUser; }
        bool operator==(const Chat &right) const;

        void addMessage(const Message& msg) {
            //controls
            chatMessages.push_back(msg);
        }

        void showChatContent() const {
            for (const auto& msg : chatMessages)
                std::cout << msg.toString() << std::endl;
        }

        ~Chat(){
            delete firstUser;
            delete secondUser;
            chatMessages.clear();
        }

        //restituire i-esimo messaggio
        //poterlo marcare come letto o non letto
        //ricerca di un messaggio sulla base di una parola
        //restituire quanti messaggi sono presenti e quanti da leggere

    private:
        std::vector<Message> chatMessages;
        User* firstUser;
        User* secondUser;
        std::string name;
};



#endif //CHAT_H