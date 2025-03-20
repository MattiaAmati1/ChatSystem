#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {

    public:
        Node(T value) {
            this->value = value;
        }

        ~Node() {
            delete nextItem; //T is never used as a pointer, no need to delete values or deep copy
        }

        Node<T>* next(){ return nextItem; }
        T getValue(){ return value; }
        void updateValue(T value) { this -> value = value; }
        void setNext(Node<T>* next) { nextItem = next; }

    private:
        T value;
        Node<T>* nextItem;

};

#endif //NODE_H
