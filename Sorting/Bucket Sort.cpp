#include <iostream>
#include <vector>
using namespace std;

void sort(vector<float> &arr, int n) {
    float min;
    int index;
    for (int i = 0; i < n - 1; i++) {
        min = arr[i];
        index = i;
        for (int j = i + 1; j < n; j++) {
            if (min > arr[j]) {
                min = arr[j];
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
}

void bucketSort(float arr[], int n){
    vector<float> bucket[n];
    for (int i = 0; i < n; i++){
        int index = arr[i] * n;
        bucket[index].push_back(arr[i]);
    }
    for (int i = 0; i < n; i++)
        sort(bucket[i], bucket[i].size());
    int index = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < bucket[i].size(); j++) {
            arr[index] = bucket[i][j];
            index++;
        }
    }
}

void print(float arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main() {
    float arr[10] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int size = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, size);
    print(arr, size);
    return 0;
}
