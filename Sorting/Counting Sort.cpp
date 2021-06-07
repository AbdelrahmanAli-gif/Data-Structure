#include <iostream>
using namespace std;

void countingSort(int arr[], int n){ // 1, 4, 1, 2, 7, 5, 2
    int max = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > max)
            max = arr[i];
    }
    int counter[max + 1];
    for (int i = 0; i < max + 1; i++)
        counter[i] = 0;
    for (int i = 0; i < n; i++){
        counter[arr[i]]++;
    }
    for (int i = 1; i < max + 1; i++)
        counter [i] += counter [i - 1];
    int arrSorted[n];
    for (int i = n - 1; i >= 0; i--) {
        arrSorted[counter[arr[i]] - 1] = arr[i];
        counter[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = arrSorted[i];
}

void print(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int size = sizeof(arr)/sizeof(arr[0]);
print(arr, size);

int main() {
    int arr[8] = {1, 4, 1, 2, 7, 5, 2, 0};
    int size = sizeof(arr)/sizeof(arr[0]);
    countingSort(arr, size);
    print(arr, size);
    return 0;
}
