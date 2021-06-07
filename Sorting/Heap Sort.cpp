#include <iostream>
using namespace std;

void heapify(int arr[], int size, int position){
    int l = 2 * position + 1;
    int r = 2 * position + 2;
    int max = position;
    if (l < size && arr[l] > arr[max])
        max = l;
    if (r < size && arr[r] > arr[max])
        max = r;
    if (max != position) {
        swap(arr[position], arr[max]);
        heapify(arr, size, max);
    }
}

void buildHeap(int arr[], int size){
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
}

void heapSort(int arr[], int size){
    buildHeap(arr, size);
    for (int i = size - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void print(int arr[], int size){
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "]" << endl;
}

int main() {
    int arr[5] = {50, 20, 5, 90, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr,size);
    print(arr, size);
    return 0;
}
