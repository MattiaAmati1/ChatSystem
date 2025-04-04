#ifndef CHATSYSTEM_SUBJECT_H
#define CHATSYSTEM_SUBJECT_H

#include "Observer.h"

class User;

class Subject{
    public:
        virtual void subscribe(Observer* o) = 0;
        virtual void unsubscribe(Observer* o) = 0;
        virtual void notify(UpdateType type) = 0;
        virtual void notify(UpdateType type, User author, User receiver, int id) = 0;
        virtual void notify(UpdateType type, User author, User receiver, Message textMessage) = 0;

        virtual ~Subject() = default;
};
#endif //CHATSYSTEM_SUBJECT_H
