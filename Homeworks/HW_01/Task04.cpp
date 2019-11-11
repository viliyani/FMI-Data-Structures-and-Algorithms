#include <iostream>
using namespace std;

bool check(long long N, long long M) {
    long long o = 1;
    long long c = 0;

    for (int i = 0; i < M - 1; i++) {
        o++;
        c++;
    }

    if (c > 0) {
        while (c < N) {
            c += 2;
        }
    }

    if (o == M && c == N) {
        return true;
    }

    return false;
}

int main() {
    int o = 1;
    int c = 0;
    int T;
    long long arrN[100];
    long long arrM[100];


    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> arrN[i];
        cin >> arrM[i];
    }

    for (int i = 0; i < T; i++) {
        if (check(arrN[i],arrM[i]) == true) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
