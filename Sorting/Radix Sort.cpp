#include <iostream>
using namespace std;

void countingSort(int arr[], int n, int div){
    int arrSorted [n];
    int counter[10] = {0};
    for (int i = 0; i < n; i++)
        counter[(arr[i] / div) % 10]++;
    for (int i = 1; i < 10; i++)
        counter[i] += counter[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        arrSorted[counter[(arr[i] / div) % 10] - 1] = arr[i];
        counter[(arr[i] / div) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = arrSorted[i];
}

void radixSort(int arr[], int n){
    int max = arr[0];
    for (int i = 1; i < n; i++){
        if (max < arr[i])
            max = arr[i];
    }
    for (int i = 1; max / i > 0; i *= 10)
        countingSort(arr, n, i);
}

void print(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int size = sizeof(arr)/sizeof(arr[0]);
print(arr, size);

int main() {
    int arr[7] = {120, 800, 55, 275, 999, 500, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr, size);
    print(arr, size);
    return 0;
}
