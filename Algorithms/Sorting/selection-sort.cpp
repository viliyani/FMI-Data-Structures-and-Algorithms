#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int * arr, int length) {
    int idx;

    for (int i = 0; i < length; i++) {
        idx = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[idx]) {
                idx = j;
            }
        }

        if (i != idx) {
            swap(arr[i], arr[idx]);
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

    selectionSort(arr, 7);

    print(arr, 7);

    return 0;
}
