#include <iostream>
using namespace std;

void shellSort(int arr[], int n){ // 5, 2, 71, 0, 10, 8, 19, 1, 21, 12
    int key, index;
    for (int i = n / 2; i > 0; i /= 2){
        for (int j = i; j < n; j++){
            index = j;
            key = arr[j];
            while (index >= i && arr[index - i] > key){
                arr[index] = arr[index - i];
                index -= i;
            }
            arr[index] = key;
        }
    }
}

int main() {
    int arr[10] = {5, 2, 71, 0, 10, 8, 19, 1, 21, 12};
    shellSort(arr, 10);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    return 0;
}
