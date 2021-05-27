#include <iostream>
using namespace std;

template <class T>
class Queue{
    int maxSize;
    int head;
    int tail;
    int count;
    T* arr;
public:
    Queue(int size){
        maxSize = size;
        tail = -1;
        head = 0;
        arr = new T[maxSize];
        count = 0;
    }

    bool isEmpty(){
        if (count == 0)
            return true;
        else
            return false;
    }

    bool isFull(){
        if (count == maxSize)
            return true;
        else
            return false;
    }

    void enqueue(T element){
        if (isFull())
            cout << "Queue is full" << endl;
        else{
            tail = (tail + 1) % maxSize;
            arr[tail] = element;
            count++;
        }
    }

    void dequeue(){
        if(isEmpty())
            cout << "Queue is empty" << endl;
        else{
            head = (head + 1) % maxSize;
            count--;
        }
    }

    T getHead(){
        if (isEmpty())
            cout << "Queue is empty" << endl;
        else
            return arr[head];
    }

    T getTail(){
        if (isEmpty())
            cout << "Queue is empty" << endl;
        else
            return arr[tail];
    }

    void print(){
        if(isEmpty())
            cout << "Queue is empty" << endl;
        else{
            cout << "[ ";
            for (int i = head; i != tail; i = (i + 1) % maxSize)
                cout << arr[i] << " ";
            cout << arr[tail] << " ]" << endl;
        }
    }

    int search(T element){
        int position = -1;
        if(isEmpty())
            cout << "Queue is empty" << endl;
        else {
            for (int i = head; i != tail; i = (i + 1) % maxSize){
                if(arr[i] == element) {
                    position = i;
                    break;
                }
            }
            if (position == -1){
                if (arr[tail] == element)
                    position = tail;
            }
        }
        return position;
    }
};

int main() {
    Queue<int> queue(5);
    queue.enqueue(10);
    queue.enqueue(5);
    queue.enqueue(15);
    queue.enqueue(20);
    queue.enqueue(9);
    queue.enqueue(12);
    cout << "Index of 5 is: " << queue.search(5) << endl;
    queue.print();
    cout << queue.getHead() << " " << queue.getTail() << endl;
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    cout << "Index of 5 is: " << queue.search(5) << endl;
    queue.enqueue(100);
    queue.print();
    cout << queue.getHead() << " " << queue.getTail() << endl;
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    return 0;
}
