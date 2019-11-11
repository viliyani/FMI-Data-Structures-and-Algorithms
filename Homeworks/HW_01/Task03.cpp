#include <iostream>
using namespace std;

int calcWater(int x1, int x2, int y1, int y2) {
    int smaller = y1 < y2 ? y1 : y2;
    return (x2 - x1) * smaller;
}

int main() {
    int N;
    int arr[100000];
    int maxWater = 0;
    int currWater = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            currWater = calcWater(i+1,j+1,arr[i],arr[j]);

            if (currWater > maxWater) {
                maxWater = currWater;
            }
        }
    }

    cout << maxWater;

    return 0;
}
