#include <iostream>
using namespace std;

int linearSearch(int * arr, int length, int target) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {
    int arr[] = {7, 3, 5, 2, 1, 4, 6};

    cout << "Index of 5 is: " << linearSearch(arr, 7, 5) << endl;
    cout << "Index of 10 is: " << linearSearch(arr, 7, 10) << endl;

    return 0;
}
