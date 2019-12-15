#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function declaration
long long binarySearch(vector<long long>&, long long, long long, long long);

int main() {
    // # Variables
    long long n; // total cups
    long long m; // total target berries
    long long value; // helper
    long long add_last = 0; // max value in each cup

    // Enter number of cups
    cin >> n;

    // Enter berries in each cup
    vector<long long> cups(n);

    for (long long i = 0; i < n; i++) {
        cin >> value;
        add_last += value;
        cups[i] = add_last;
    }

    // Enter targeted berries
    cin >> m;

    vector<long long> berries(m);

    for (long long i = 0; i < m; i++)
    {
        cin >> berries[i];
    }

    // Find answers
    for (long long i = 0; i < m; i++)
    {
        if (berries[i] <= cups[0]) {
            cout << 1 << "\n";
        } else {
            cout << binarySearch(cups, 1, n - 1, berries[i]) + 1 << "\n";
        }
    }

    return 0;
}

// Function definition
long long binarySearch(vector<long long>& arr, long long left, long long right, long long x) {
    if (left > right) {
        return -1;
    }

    long long mid = (left + right) / 2;

    if (x <= arr[mid] && x > arr[mid - 1]) {
        return mid;
    } else if (x < arr[mid]) {
        return binarySearch(arr, left, mid - 1, x);
    } else {
        return binarySearch(arr, mid + 1, right, x);
    }
}

