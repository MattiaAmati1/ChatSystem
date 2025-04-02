#ifndef LIST_H
#define LIST_H

/*
 Personal implementation of a linked list, allows only
 the operations needed for this project in an easier way
 than an STL data structure
 */

template <typename T>
struct Node {
    T value;
    Node* next;
};

template<typename T>
class List {

    public:

        List() {
            this -> size = 0;
        }
        explicit List(T firstValue) : size(1) {
            Node<T>* newNode;
            head = newNode;
            head -> value = firstValue;
            head -> next = nullptr;

            delete newNode;
        }

        ~List() = default;

        void add(T item) {
            Node<T>* newNode;
            newNode -> value = item;
            newNode -> next = head;

            head = newNode;

            delete newNode;
        }


        bool remove(T target) {
            if(size <= 1) {
                return false;
            }

            Node<T> *prevTmp = head;
            Node<T> *tmp = head -> next;
            while(tmp -> next != nullptr) {

                if(tmp -> value == target) { //requires a == operator for type T
                    prevTmp -> next = tmp -> next; //prev -> next = tmp, tmp is to be removed
                    size--;
                    delete tmp;
                    delete prevTmp;
                    return true;
                }

                prevTmp = prevTmp -> next;
                tmp = tmp -> next;
            }

            delete prevTmp;
            delete tmp;

            return false;
        }

        bool contains(T item) {
            if(size <= 1) {
                return false;
            }
            Node<T> *temp = head;
            while(temp != nullptr) {
                if(temp->value == item) { //assumes that the T type has a well-defined == operator
                    return true;
                }
                temp = temp -> next;
            }

            return false;
        }



        Node<T> *first() const { return head; }
        const int &getSize() const { return size; }

    private:
        int size;
        Node<T>* head;
};

#endif //LIST_H
