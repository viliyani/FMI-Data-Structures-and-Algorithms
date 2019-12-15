#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<long long> & huts, int N, int K, int mid) {
    int pos = huts[0];
    int elements = 1;

    for (int i = 1; i < N; i++) {
        if (huts[i] - pos >= mid) {
            pos = huts[i];
            elements++;

            if (elements == K) {
                return true;
            }
        }
    }

    return false;
}

long long findMinDist(vector<long long> & huts, int N, int K) {
    long long left = huts[0];
    long long right = huts[N - 1];
    long long res = -1;

    while (left < right) {
        long long mid = (left + right) / 2;

        if (isPossible(huts, N, K, mid)) {
            if (mid > res) {
                res = mid;
            }
            left = mid+1;
        } else {
            right = mid;
        }
    }

    return res;
}

int main() {
    // # Variables
    long long N; // total huts
    long long K; // total cows
    long long remainingCows; // cows that need to be placed to huts

    // Enter number of huts
    cin >> N;

    // Enter number of cows
    cin >> K;

    remainingCows = K;

    vector<long long> huts(N);

    // Enter coordinates for each hut
    for (long long i = 0; i < N; i++) {
        cin >> huts[i];
    }

    // Sort coordinates of huts
    sort(huts.begin(), huts.end());

    // Find min distance
    cout << findMinDist(huts, N, K);

    return 0;
}
