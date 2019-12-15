#include <iostream>
using namespace std;

int _binarySearch(int * arr, int left, int right, int target) {
    if (right - left < 0) {
        return -1;
    }

    int mid = (right + left) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return _binarySearch(arr, left, mid - 1, target);
    } else if (arr[mid] < target) {
        return _binarySearch(arr, mid + 1, right, target);
    }

    return -1;
}

int binarySearch(int * arr, int length, int target) {
    return _binarySearch(arr, 0, length - 1, target);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    cout << "Index of 5 is: " << binarySearch(arr, 7, 5) << endl;
    cout << "Index of 10 is: " << binarySearch(arr, 7, 10) << endl;

    return 0;
}
