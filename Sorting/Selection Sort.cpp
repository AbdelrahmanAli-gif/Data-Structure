#include <iostream>
using namespace std;

void selectionSort(int arr[], int size){
    int min, index;
    for (int i = 0; i < size; i++){
        min = arr[i];
        index = i;
        for (int j = i + 1; j < size; j++){
            if (arr[j] < min){
                min = arr[j];
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
}

void print(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int size = sizeof(arr)/sizeof(arr[0]);
print(arr, size);

int main() {
    int arr[6] = {60, 40, 50, 30, 10, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, size);
    print(arr, size);
    return 0;
}
