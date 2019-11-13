#include <iostream>
using namespace std;

void swap(long long & a, long long & b) {
    long long tmp = a;
    a = b;
    b = tmp;
}

void selectionSort(long long * array, long long * array2, int length) {
    for (int i = 0; i < length; i++) {
        int index = i;

        for (int k = i + 1; k < length; k++) {
            if (array[k] < array[index]) {
                index = k;
            }
        }

        swap(array[i], array[index]);
        swap(array2[i], array2[index]);
    }
}


int main() {
    // Variables
    int n;
    long long arrBi[1000000];
    long long arrTi[1000000];

    // Input
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arrBi[i];
        cin >> arrTi[i];
    }

    // SORT
    long long * arrStart = &arrBi[0];
    long long * arrStart2 = &arrTi[0];

    selectionSort(arrStart, arrStart2, n);

    // # Algorithm
    long long currsum = arrBi[0] + arrTi[0];
    long long nextsum;
    int br = 0;

    for (int i = 1; i < n; i++) {
        nextsum = arrBi[i] + arrTi[i];
        if (currsum <= nextsum) {
            br++;
            currsum = nextsum;
        }
    }

    cout << br;

    return 0;
}
