#ifndef CHAT_H
#define CHAT_H

#include <utility>
#include <iostream>
#include <vector>
#include "Message.h"

class Chat{

    public:

        Chat(std::string firstName, std::string secondName, std::string chatName = "Unnamed Chat") :
                firstUserName(std::move(firstName)), secondUserName(std::move(secondName)), name(std::move(chatName)) {}

        //adds a warning if the method is called bypassing the return value
        [[nodiscard]] std::string getFirstUserName() const { return firstUserName; }
        [[nodiscard]] std::string getSecondUserName() const { return secondUserName; }
        bool operator==(const Chat &right) const {
            return firstUserName == right.firstUserName && secondUserName == right.secondUserName ||
                   firstUserName == right.secondUserName && secondUserName == right.firstUserName;
        }

        void addMessage(const Message& msg) { chatMessages.push_back(msg); }

        void showChatContent() const {
            for (const auto& msg : chatMessages)
                std::cout << msg.toString() << std::endl;
        }

        ~Chat(){ chatMessages.clear(); }

        //restituire i-esimo messaggio
        //poterlo marcare come letto o non letto
        //ricerca di un messaggio sulla base di una parola
        //restituire quanti messaggi sono presenti e quanti da leggere

    private:
        std::vector<Message> chatMessages;
        std::string firstUserName;
        std::string secondUserName;
        std::string name;
};



#endif //CHAT_H