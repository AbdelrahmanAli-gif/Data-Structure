#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

template <class T>
class Stack{
    int top;
    T items[MAX_SIZE];
public:
    Stack(){
        top = -1;
    }

    void push(T element){
        if (top >= MAX_SIZE - 1)
            cout << "Stack is full in push" << endl;
        else{
            top++;
            items[top] = element;
        }
    }

    bool isEmpty(){
        if(top == -1)
            return true;
        else
            return false;
    }

    void pop(){
        if (isEmpty())
            cout << "Stack is empty in pop" << endl;
        else
            top--;
    }

    T getTop(){
        if (isEmpty())
            cout << "Stack is empty in getTop" << endl;
        else
            return items[top];
    }

    void print(){
        cout << "[ ";
        for (int i = top; i >= 0; i--)
            cout << items[i] << " ";
        cout << "]" << endl;
    }
};

int main() {
    Stack<int> stack;
    stack.push(10);
    stack.push(15);
    stack.push(5);
    stack.push(20);
    stack.push(9);
    stack.push(25);
    cout << stack.getTop() << endl;
    stack.print();
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
