#include <iostream>
using namespace std;

int partition (int arr[], int l, int r, int key){ // 10, 16, 8, 12, 15, 6, 4, 9, 5, 50
    while (l <= r){
        while (arr[l] < key)
            l++;
        while (arr[r] > key)
            r--;
        if (l <= r){
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
    return l;
}

void quickSort(int arr[], int l, int r){
    if (l < r){
        int key = arr[(l + r) / 2];
        int pivot = partition(arr, l, r, key);
        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot, r);
    }
}

int main() {
    int arr[10] = {10, 16, 8, 12, 15, 6, 4, 9, 5, 50};
    quickSort(arr, 0, 10);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    return 0;
}
