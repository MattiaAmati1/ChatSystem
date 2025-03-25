#ifndef LIST_H
#define LIST_H

/*
 Personal implementation of a linked list, allows only
 the operations needed for this project in an easier way
 than an STL data structure
 */

template <typename T>
class Node {
public:
    explicit Node(T value) : value(value), nextItem(nullptr){}

    ~Node() { }

    Node<T>* next(){ return nextItem; }
    T getValue(){ return value; }
    void updateValue(T newValue) { this -> value = newValue; }
    void setNext(Node<T>* next) { this -> nextItem = next; }

private:
    T value;
    Node<T>* nextItem;
};

template<typename T>
class List {

    public:

        explicit List(T firstValue) : size(1) {
            Node<T>* newNode = new Node<T>(firstValue);
            head = newNode;
            head -> setNext(nullptr);

            delete newNode;
        }

        ~List() {
            /*
            clear();
            delete head;
            delete tail;
            */
        }


        void add(T item) {
            Node<T>* newNode = new Node<T>(item);

            newNode ->setNext(head);
            head = newNode;

            delete newNode;
        }


        void remove(T target) {
            if(size <= 1) {
                return;
            }

            Node<T> *prevTmp = head;
            Node<T> *tmp = head -> next();
            while(tmp -> next() != nullptr) {

                if(tmp -> getValue() == target) { //requires a == operator for type T
                    prevTmp ->setNext(tmp -> next()); //prev -> next = tmp, tmp is to be removed
                    size--;
                    delete tmp;
                    delete prevTmp;
                    return;
                }

                prevTmp = prevTmp -> next();
                tmp = tmp -> next();
            }

            delete prevTmp;
            delete tmp;
        }

        bool contains(T item) {
            if(size <= 1) {
                return false;
            }
            Node<T> *temp = head;
            while(temp != nullptr) {
                if(temp -> getValue() == item) { //assumes that the T type has a well-defined == operator
                    return true;
                }
                temp = temp->next();
            }

            return false;
        }

        const int &getSize() const { return size; }

        void clear() {
            Node<T> *firstTmp = head;
            Node<T> *secondTmp = head -> next();

        }

        Node<T> *first() const { return head; }



    private:
        int size;
        Node<T>* head;
};

#endif //LIST_H
