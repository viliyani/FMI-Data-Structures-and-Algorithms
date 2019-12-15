#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int * arr, int length) {
    for (int i = 1; i < length; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j-1]; j--) {
             swap(arr[j], arr[j-1]);
        }
    }
}

void print(int * arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {7, 3, 5, 2, 1, 4, 6};

    print(arr, 7);

    insertionSort(arr, 7);

    print(arr, 7);

    return 0;
}
