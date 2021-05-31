#include <iostream>
using namespace std;

template <class T>
class LinkedList{
    struct Node{
        T item;
        Node* next;
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
        Node *temp = new Node;
        temp->item = element;
        if (isEmpty()){
            head = temp;
            tail = temp;
            tail->next = NULL;
            head->next = NULL;
        }else {
            temp->next = head;
            head = temp;
        }
        length++;
    }

    void insertLast(T element){
        Node *temp = new Node;
        temp->item = element;
        temp->next = NULL;
        if (isEmpty()){
            head = temp;
            tail = temp;
            tail->next = NULL;
            head->next = NULL;
        }else {
            tail->next = temp;
            tail = temp;
        }
        length++;
    }

    void insertAt(T element, int position){
        if (position > length || position < 0)
            cout << "Invalid position" << endl;
        else{
            if (position == 0)
                insertFirst(element);
            else if (position == length)
                insertLast(element);
            else {
                Node *temp = new Node;
                temp->item = element;
                Node *current = new Node;
                current = head;
                for (int i = 1; i < position; i++)
                    current = current->next;
                temp->next = current->next;
                current->next = temp;
                length++;
            }
        }
    }

    void removeFirst(){
        if (isEmpty())
            cout << "List is empty" << endl;
        else {
            Node *temp = head;
            if (length == 1) {
                head = NULL;
                tail = NULL;
            }else{
                head = temp->next;
                temp->next = NULL;
            }
            delete temp;
            length--;
        }
    }

    void removeLast(){
        if (isEmpty())
            cout << "List is empty" << endl;
        else {
            Node *temp = tail;
            if (length == 1){
                head = NULL;
                tail = NULL;
            }else {
                Node *current = new Node;
                current = head;
                for (int i = 1; i < length - 1; i++)
                    current = current->next;
                current->next = NULL;
                tail = current;
            }
            delete temp;
            length--;
        }
    }

    void removeAt(int position){
        if (position > length - 1 || position < 0)
            cout << "Invalid index" << endl;
        else{
            if (position == 0)
                removeFirst();
            else if (position == length - 1)
                removeLast();
            else{
                Node* current = head;
                Node* temp = new Node;
                for (int i = 1; i < position; i++)
                    current = current->next;
                temp = current->next;

                current->next = temp->next;
                temp->next = NULL;
                delete temp;
                length--;
            }
        }
    }

    void reverse(){
        Node* current = head;
        Node* next = current->next;
        Node* previous = NULL;
        while (current != NULL){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }

    int search(T element){
        int position = -1;
        Node* current = head;
        for (int i = 0; i < length; i++){
            if (current->item == element){
                position = i;
                break;
            } else
                current = current->next;
        }
        cout << "Element is found at index: ";
        return position;
    }

    T getHead(){
        if (isEmpty())
            cout << "List is empty" << endl;
        else
            return head->item;
    }

    T getTail(){
        if (isEmpty())
            cout << "List is empty" << endl;
        else
            return tail->item;
    }

    void display(){
        Node* current = new Node;
        current = head;
        cout << "[ ";
        for (int i = 0; i < length; i++){
            cout << current->item << " ";
            current = current->next;
        }
        cout << "]" << endl;
    }
};

int main() {
    LinkedList<int> linkedList;
    linkedList.insertLast(5);
    linkedList.insertLast(6);
    linkedList.insertLast(7);
    linkedList.insertFirst(0);
    linkedList.insertFirst(1);
    linkedList.insertFirst(2);
    linkedList.insertAt(10, 0);
    linkedList.insertAt(15,7);
    linkedList.removeFirst();
    linkedList.removeLast();
    linkedList.removeAt(3);
    cout << linkedList.getHead() << " " << linkedList.getTail() << endl;
    linkedList.display();
    linkedList.reverse();
    linkedList.display();
    cout << linkedList.search(0) << endl;
    cout << linkedList.search(10) << endl;
    return 0;
}
