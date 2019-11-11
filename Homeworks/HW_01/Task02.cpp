#include <iostream>
using namespace std;

int main() {
    int M, N;
    long long arr[1000];
    long long toGive = 0;
    long long toFill = 0;

    cin >> M;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        if (arr[i] > M) {
            toGive += arr[i] - M;
        }

        if (arr[i] < M) {
            toFill += M - arr[i];
        }
    }

    if (toGive >= toFill) {
        cout << "yes";
    } else {
        cout << "no";
    }

    return 0;
}
