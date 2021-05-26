#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){ // 100, 60, 20, 50, 30, 90
    bool swapped = false;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped)
            break;
    }
}

int main() {
    int arr[6] = {100, 60, 20, 50, 30, 90};
    bubbleSort(arr, 6);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
    return 0;
}
