#ifndef CHATSYSTEM_OBSERVER_H
#define CHATSYSTEM_OBSERVER_H

class Observer{

    public:
        virtual void attach() = 0;
        virtual void detach() = 0;
        virtual void update() = 0;

        virtual ~Observer() = default;
};


#endif //CHATSYSTEM_OBSERVER_H
