#include <bits/stdc++.h>
#define ll long long
#define MAX 1000000000000000000
using namespace std;

int main() {
    // # Variables
    ll n, m;

    // # Input
    cin >> n >> m;

    ll a[n], b[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // # Algorithm
    ll ans = 0;
    ll left = 0, right = MAX, mid, temp;

    // # Find
    while (left <= right) {
        mid = (left + right) / 2;
        temp = 0;

        for (ll i = 0; i < n; i++) {
            ll Ci = a[i] - (mid / b[i]);
            if (Ci > 0) {
                temp += Ci;
            }
        }

        if (temp <= m) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}

