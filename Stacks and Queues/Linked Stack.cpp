#include <iostream>
using namespace std;

template <class T>
class Stack{
    struct Node{
        T value;
        Node* next;
    };
    Node* top;
    Node* current;
public:
    Stack(){
        top = NULL;
        current = NULL;
    }

    void push(T element){
        Node* elementPtr = new Node;
        elementPtr->value = element;
        elementPtr->next = top;
        top = elementPtr;
    }

    bool isEmpty(){
        if (top == NULL)
            return true;
        else
            return false;
    }

    void pop(){
        if (isEmpty())
            cout << "Stack is empty in pop" << endl;
        else{
            Node* temp = new Node;
            temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }

    T getTop(){
        if (top == NULL)
            cout << "Stack is empty in getTop" << endl;
        else
            return top->value;
    }

    void print(){
        current = top;
        cout << "[ ";
        while(current != NULL){
            cout << current->value << " ";
            current = current->next;
        }
        cout << "]" << endl;
    }
};

int main() {
    Stack<int> stack;
    stack.push(10);
    stack.push(15);
    stack.push(20);
    stack.push(5);
    stack.push(25);
    stack.print();
    cout << stack.getTop() << endl;
    stack.pop();
    stack.pop();
    stack.pop();
    stack.print();
    cout << stack.getTop() << endl;
    stack.pop();
    stack.pop();
    stack.pop();
    return 0;
}
