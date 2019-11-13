#include <iostream>
using namespace std;

int main() {
    // # Variables
    int arr[200000] = {0}; // Monsters. arr[0] = dark hole; arr[15] = 3 -> 3 monsters at position 15
    int n; // Total monsters
    int x; // Distance
    int pos; // Helper
    int maxPosition = 0; // The rightmost monster
    int aliveMonsters = 0; // Total alive monsters
    int counter = 0; // Total shoots

    // # Input
    cin >> n;
    cin >> x;

    for (int i = 0; i < n; i++) {
        cin >> pos;
        arr[pos]++;
        if (maxPosition < pos) {
            maxPosition = pos;
        }
    }

    // # Algorithm -> Basic idea: Kill every time the rightmost monster

    aliveMonsters = n;

    // While there is alive monsters -> Kill the monsters on the rightmost position and move the others
    while (aliveMonsters > 0) {
        arr[maxPosition] = 0;
        counter++;

        for (int i = 1; i < maxPosition; i++) {
            if (arr[i] == 0) {
                continue;
            } else {
                // Move the monsters on this position with "x"

                if (i-x >= 1) {
                    arr[i-x] = arr[i];

                    if (maxPosition < (i-x)) {
                        maxPosition = (i-x);
                    }
                }
                aliveMonsters -= arr[i];
                arr[i] = 0;
            }
        }
    }

    // Print the result
    cout << counter;

    return 0;
}
