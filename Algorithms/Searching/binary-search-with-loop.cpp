#include <iostream>
using namespace std;

int binarySearch(int * arr, int length, int target) {
    int left = 0;
    int right = length - 1;

    while ( left <= right ) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    cout << "Index of 5 is: " << binarySearch(arr, 7, 5) << endl;
    cout << "Index of 10 is: " << binarySearch(arr, 7, 10) << endl;

    return 0;
}
