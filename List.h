#ifndef LIST_H
#define LIST_H
#include "Node.h"

/*
 Personal implementation of a linked list, allows only
 the operations needed for this project in an easier way
 than an STL data structure
 */

template<typename T>
class List {

    public:
        List() : size(0) {
            head = nullptr;
            tail = nullptr;
            tail -> setNext(nullptr);
        }

        ~List() {
            clear();
            delete head;
            delete tail;

        }

        void add(T item) {
            Node<T> *newNode = new Node<T>(item);
            if(size == 0) {
                head = newNode;
                tail = newNode;
                size++;
            }else {
                tail -> setNext(newNode);
                tail = tail->next();
                tail -> setNext(nullptr);
                size++;
            }

            delete newNode;
        }

        void remove(T item) {
            if(size == 0) {
                return;
            }

            Node<T> *temp = head;
            while(temp->next() != nullptr) {

                if(temp->next()->item() == item) {
                    temp -> setNext(temp->next()->next());
                    delete temp->next();
                    size--;
                    delete temp;
                    return;
                }

                temp = temp->next();
            }

            delete temp;

        }

        const int &getSize() const { return size; }

        void clear() {
            Node<T> *firstTmp = head;
            Node<T> *secondTmp = head -> next();
            while(secondTmp -> next() != nullptr) {
                delete firstTmp;
                firstTmp = secondTmp -> next();
            }

            delete firstTmp; //deleting null pointers has no effect
            delete secondTmp;
        }

        Node<T> *first() const { return head; }
        Node<T> *last() const { return tail; }

    private:
        int size;
        Node<T>* head;
        Node<T>* tail;
};



#endif //LIST_H
