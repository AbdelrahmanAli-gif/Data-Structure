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

int main() {
    int arr[5] = {13991, 23371, 31295, 13684, 16278};
    quickSort(arr, 0, 5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    return 0;
}
