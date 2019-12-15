#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int * array, int start, int end) {
    int pivot = array[(start + end) / 2];
    int left = start - 1;
    int right = end + 1;

    while (true) {
        do {
            left++;
        } while (array[left] < pivot);

        do {
            right--;
        } while (array[right] > pivot);

        if (left >= right) {
            return right;
        }

        swap(array[left], array[right]);
    }
}

void _quickSort(int * array, int start, int end) {
    if (start < end) {
        int pivot = partition(array, start, end);
        _quickSort(array, start, pivot - 1);
        _quickSort(array, pivot + 1, end);
    }
}

void quickSort(int * array, int length) {
    _quickSort(array, 0, length - 1);
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

    quickSort(arr, 7);

    print(arr, 7);

    return 0;
}
