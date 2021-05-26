#include <iostream>
using namespace std;

void selectionSort(int arr[], int n){ // 60, 40, 50, 30, 10, 20
    int min, index;
    for (int i = 0; i < n - 1; i++){
        min = arr[i];
        index = i;
        for (int j = i + 1; j < n; j++){
            if (min > arr[j]) {
                min = arr[j];
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
}

int main() {
    int arr[6] = {60, 40, 50, 30, 10, 20};
    selectionSort(arr, 6);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
    return 0;
}
