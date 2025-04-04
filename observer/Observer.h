#ifndef CHATSYSTEM_OBSERVER_H
#define CHATSYSTEM_OBSERVER_H

#include "../User.h"

class User;

enum class UpdateType{
    CHAT_CREATED,
    MESSAGE_SENT,
    MEMBER_ADDED,
    MEMBER_REMOVED,
    DEFAULT,
};

class Observer{

    public:
        virtual void attach() = 0;
        virtual void detach() = 0;
        virtual void update(UpdateType type) = 0;
        virtual void update(UpdateType type, User author, User receiver, int id) = 0;
        virtual void update(UpdateType type, User author, User receiver, Message textMessage) = 0;

        virtual ~Observer() = default;
};


#endif //CHATSYSTEM_OBSERVER_H
