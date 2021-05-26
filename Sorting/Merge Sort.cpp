#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){ // 60, 10, 20, 5, 60, 70
    int n1 = m - l +1;
    int n2 = r - m;
    int arr1[n1];
    int arr2[n2];
    for (int i = 0; i < n1; i++)
        arr1[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        arr2[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2){
        if (arr1[i] < arr2[j]){
            arr[k] = arr1[i];
            i++;
        }
        else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if (l < r){
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[6] = {60, 10, 20, 5, 60, 70};
    mergeSort(arr, 0, 6);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
    return 0;
}
