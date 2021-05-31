#include <iostream>
using namespace std;

template <class T>
class ArrayList{
    T* arr;
    int maxSize;
    int length;
public:
    ArrayList(int size){
        if (size < 0)
            maxSize = 10;
        else
            maxSize = size;
        arr = new T[maxSize];
        length = 0;
    }

    bool isEmpty(){
        if (length == 0)
            return true;
        else
            return false;
    }

    bool isFull(){
        if (length == maxSize)
            return true;
        else
            return false;
    }

    int getSize(){
        return length;
    }

    void insertAt(T element, int position) {
        if (isFull())
            cout << "List is full" << endl;
        else if (position > length || position < 0)
            cout << "Invalid index" << endl;
        else {
            for (int i = length; i > position; i--)
                arr[i] = arr[i - 1];
            arr[position] = element;
            length++;
        }
    }

    void deleteAt(int position){
        if (isEmpty())
            cout << "List is empty" << endl;
        else if (position > length - 1 || position < 0)
            cout << "Invalid index" << endl;
        else{
            for (int i = position; i < length - 1; i++)
                arr[i] = arr[i + 1];
            length--;
        }
    }

    void update(T element, int position){
        if (position < 0 || position > length - 1)
            cout << "Invalid index" << endl;
        else
            arr[position] = element;
    }

    T getElementAt(int position){
        if (position < 0 || position > length - 1)
            cout << "Invalid index" << endl;
        else
            return arr[position];
    }

    int search(T element) {
        int position = -1;
        for (int i = 0; i < length; i++) {
            if (arr[i] == element) {
                position = i;
                break;
            }
        }
        cout << "Element is at index: ";
        return position;
    }

    void print(){
        if (isEmpty())
            cout << "List is empty" << endl;
        else{
            cout << "[ ";
            for (int i = 0; i <length ; i++)
                cout << arr[i] << " ";
            cout << "]" << endl;
        }
    }
};

int main() {
    ArrayList<int> arrayList(5);
    arrayList.insertAt(1,0);
    arrayList.insertAt(2,1);
    arrayList.insertAt(3,2);
    arrayList.insertAt(4,3);
    arrayList.insertAt(5,4);
    arrayList.print();
    arrayList.deleteAt(4);
    arrayList.print();
    arrayList.update(10,3);
    arrayList.print();
    cout << arrayList.search(2) << endl;
    cout << arrayList.getElementAt(0) << endl;
    return 0;
}
