#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size){
    bool swapped = false;
    for (int i = 0; i < size - 1 - i; i++){
        for (int j = 0; j < size - 1 - i; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped){
            break;
        }
    }
}

void print(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[6] = {100, 60, 20, 50, 30, 90};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, 6);
    print(arr, size);
    return 0;
}
