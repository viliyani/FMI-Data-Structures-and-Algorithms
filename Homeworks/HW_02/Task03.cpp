#include <iostream>
using namespace std;

int calcEnergy(int * arr, int length) {
    int counter = 0;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                counter++;
            }
        }
    }

    return counter;
}

int main() {
    int * arr; // Array with heights of the buildings
    int n;

    cin >> n;

    arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << calcEnergy(arr, n);

    delete[] arr;

    return 0;
}
