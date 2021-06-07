#include <iostream>
using namespace std;

int partition (int arr[], int start, int end){ // 10, 16, 8, 12, 15, 6, 4, 9, 5, 50
    int pivot = arr[start];
    int l = start;
    int r = end;
    while (l < r) {
        do {
            l++;
        } while (arr[l] <= pivot);
        do {
            r--;
        } while (arr[r] > pivot);
        if(l < r)
            swap(arr[l], arr[r]);
    }
    swap(arr[start], arr[r]);
    return r;
}

void quickSort(int arr[], int start, int end){
    if (start < end){
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot);
        quickSort(arr, pivot + 1, end);
    }
}

void print(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[5] = {13991, 23371, 31295, 13684, 16278};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, size);
    print(arr, size);
    return 0;
}
