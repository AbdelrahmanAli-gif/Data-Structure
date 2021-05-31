#include <iostream>
using namespace std;

template <class T>
class LinkedList{
    struct Node{
        T item;
        Node* next;
        Node* previous;
    };
    Node* head;
    Node* tail;
    int length;
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
        length = 0;
    }

    bool isEmpty(){
        if (length == 0)
            return true;
        else
            return false;
    }

    void insertFirst(T element){
        Node* temp = new Node;
        temp->item = element;
        if(isEmpty()){
            temp->previous = NULL;
            temp->next = NULL;
            head = temp;
            tail = temp;
        }else{
            temp->previous = NULL;
            temp->next = head;
            head->previous = temp;
            head = temp;
        }
        length++;
    }

    void insertLast(T element){
        Node* temp = new Node;
        temp->item = element;
        if (isEmpty()){
            temp->previous = NULL;
            temp->next = NULL;
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            temp->previous = tail;
            temp->next = NULL;
            tail = temp;
        }
        length++;
    }

    void insertAt(T element, int position){
        if (position > length || position < 0)
            cout << "Invalid index" << endl;
        else {
            if (position == 0)
                insertFirst(element);
            else if (position == length)
                insertLast(element);
            else{
                Node *temp = new Node;
                temp->item = element;
                Node* current = head;
                for (int i = 1; i < position; i++)
                    current = current->next;
                temp->next = current->next;
                temp->previous = current;
                current->next->previous = temp;
                current->next = temp;
                length++;
            }
        }
    }

    void removeFirst(){
        if (isEmpty())
            cout << "List is empty" << endl;
        else{
            Node* temp = head;
            if (length == 1){
                head = NULL;
                tail = NULL;
            }else{
                head = temp->next;
                head->previous = NULL;
            }
            delete temp;
            length--;
        }
    }

    void removeLast(){
        if (isEmpty())
            cout << "List is empty" << endl;
        else{
            Node* temp = tail;
            if (length == 1){
                tail = NULL;
                head = NULL;
            }else{
                tail = temp->previous;
                tail->next = NULL;
            }
            delete temp;
            length--;
        }
    }

    void removeAt(int position){
        if (position > length - 1 || position < 0)
            cout << "Invalid Index" << endl;
        else{
            if (position == 0)
                removeFirst();
            else if (position == length - 1)
                removeLast();
            else{
                Node* current = head;
                for (int i = 0; i < position; i++)
                    current = current->next;
                current->previous->next = current->next;
                current->next->previous = current->previous;
                delete current;
                length--;
            }
        }
    }

    void display(){
        if(isEmpty())
            cout << "List is empty" << endl;
        else {
            Node *current = head;
            cout << "[ ";
            while (current != NULL) {
                cout << current->item << " ";
                current = current->next;
            }
            cout << "]" << endl;
        }
    }

    void reverse(){
        if(isEmpty())
            cout << "List is empty" << endl;
        else {
            Node *current = tail;
            cout << "[ ";
            while (current != NULL) {
                cout << current->item << " ";
                current = current->previous;
            }
            cout << "]" << endl;
        }
    }
};

int main() {
    LinkedList<int> linkedList;
    linkedList.insertFirst(5);
    linkedList.insertFirst(10);
    linkedList.insertLast(15);
    linkedList.insertLast(20);
    linkedList.insertAt(7,2);
    linkedList.insertAt(9,3);
    linkedList.insertAt(19,0);
    linkedList.insertAt(25,7);
    linkedList.display();
    linkedList.removeFirst();
    linkedList.removeLast();
    linkedList.removeAt(3);
    linkedList.display();
    //linkedList.reverse();
    return 0;
}
