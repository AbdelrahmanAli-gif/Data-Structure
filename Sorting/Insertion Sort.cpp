#include <iostream>
using namespace std;

void insertionSort(int arr[], int size){
    int key, j;
    for (int i = 0; i < size; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print(int arr[], int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    endl;
}

int main() {
    int arr[7] = {80,90,60,30,50,70,40};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    print(arr, size);
    return 0;
}
