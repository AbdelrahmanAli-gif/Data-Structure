#include <iostream>
using namespace std;

template <class T>
class Queue{
    struct Node{
        T value;
        Node* next;
    };
    Node* head;
    Node* tail;
public:
    Queue(){
        head = NULL;
        tail = NULL;
    }

    bool isEmpty(){
        if (head == NULL && tail == NULL)
            return true;
        return false;
    }

    void enqueue(T element){
        if(isEmpty()){
            head = new Node;
            head->value = element;
            head->next = NULL;
            tail = head;
        }
        else{
            Node* newPtr = new Node;
            newPtr->value = element;
            newPtr->next = NULL;
            tail->next = newPtr;
            tail = newPtr;
        }
    }

    void dequeue(){
        if(isEmpty())
            cout << "Queue is empty" << endl;
        else{
            Node *temp = new Node;
            temp = head;
            if(head == tail) {
                head = NULL;
                tail = NULL;
            }
            else {
                head = head->next;
                temp->next = NULL;
            }
            delete temp;
        }
    }

    T getHead(){
        if(isEmpty())
            cout << "Queue is empty" << endl;
        else
            return head->value;
    }

    T getTail(){
        if(isEmpty())
            cout << "Queue is empty" << endl;
        else
            return tail->value;
    }

    void print(){
        if (isEmpty())
            cout << "Queue is empty" << endl;
        else {
            Node *current = new Node;
            current = head;
            cout << "[ ";
            while ((current != NULL)) {
                cout << current->value << " ";
                current = current->next;
            }
            cout << "]" << endl;
        }
    }

    void clear(){
        Node* current;
        while(head != NULL){
            current = head;
            head = head->next;
            delete current;
        }
        tail = NULL;
    }
};

int main() {
    Queue<int> queue;
    queue.dequeue();
    queue.enqueue(10);
    queue.enqueue(15);
    queue.enqueue(5);
    queue.enqueue(20);
    queue.enqueue(19);
    queue.print();
    cout << queue.getHead() << endl;
    cout << queue.getTail() << endl;
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.print();
    queue.clear();
    queue.print();
    return 0;
}
