#ifndef CHATREGISTER_H
#define CHATREGISTER_H

#include "Chat.h"
#include "List.h"
#include "User.h"

class ChatRegister : public Observer{

    public:
        ChatRegister() = default;

        void attach() override {
            for(auto subject : subjects)
                subject -> subscribe(this);
        }

        void detach() override {
            for(auto subject : subjects)
                subject ->unsubscribe(this);
        }

        void update(UpdateType type) override{
            switch(type){

                case UpdateType::CHAT_CREATED:
                    break;
                case UpdateType::MESSAGE_SENT:
                    dataInput("data.txt");
                    if(!dataInput.is_open())
                        return;



                    break;
                case UpdateType::MEMBER_ADDED:

                    break;
                case UpdateType::MEMBER_REMOVED:
                    break;
                case UpdateType::DEFAULT:
                    break;
            }
        }


        ~ChatRegister() {

        }

    private:
        std::list<User*> subjects;
        List<Chat> chats;
        std::ifstream dataInput;
};




#endif //CHATREGISTER_H
