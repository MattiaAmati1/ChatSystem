#ifndef CHATSYSTEM_OBSERVER_H
#define CHATSYSTEM_OBSERVER_H


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

        virtual ~Observer() = default;
};


#endif //CHATSYSTEM_OBSERVER_H
