#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){ // 80,90,60,30,50,70,40
    int key, j;
    for (int i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[7] = {80,90,60,30,50,70,40};
    insertionSort(arr, 7);
    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
    return 0;
}
