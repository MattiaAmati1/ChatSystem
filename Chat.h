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

        [[nodiscard]] int getMessagesAmount() const { return chatMessages.size(); }
        [[nodiscard]] int getUnreadMessagesAmount() const {
            int total = 0;
            for (const auto& msg : chatMessages)
                if(!msg.isRead())
                    total++;

            return total;
        }

        Message& getMessageAtPosition(const int index) { return chatMessages.at(index); }
        std::string getName(){ return name; }
        void setReadStatus(const int index, const bool readStatus) {chatMessages.at(index).setRead(readStatus); }

        [[nodiscard]] std::vector<Message> getMessagesWithWord(const std::string& word) const {

            std::vector<Message> messages;
            for (auto& msg : chatMessages)
                if(msg.getText().contains(word))
                    messages.push_back(msg);

            return messages;
        }

        ~Chat(){ chatMessages.clear(); }

    private:
        std::vector<Message> chatMessages;
        std::string firstUserName;
        std::string secondUserName;
        std::string name;
};

#endif //CHAT_H