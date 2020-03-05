#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

bool checkTeams(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0) {
            return false;
        }
    }
    return true;
}

int findMaxElement(vector<int> &v, vector<int> &teams) {
    int maxElem = INT_MIN;
    int maxIdx = -1;

    for (int i = 0; i < v.size(); i++) {
        if (teams[i] == 0 && v[i] > maxElem) {
            maxIdx = i;
            maxElem = v[i];
        }
    }
    return maxIdx;
}

int main() {
    // # Input
    int n, k, x;

    cin >> n >> k;

    vector<int> v;
    vector<int> teams(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    // # Algorithm
    int team = 1;
    int idx = 0;
    int bestIdx = 0;
    int leftK = 0;
    int rightK = 0;
    int leftIdx, rightIdx;

    while (!checkTeams(teams)) {
        bestIdx = findMaxElement(v, teams);

        // Set team to best
        teams[bestIdx] = team;

        // Set team to "k" students on left
        leftIdx = bestIdx-1;
        leftK = 0;
        while (true) {
            if (teams[leftIdx] == 0) {
                teams[leftIdx] = team;
                leftK++;
            }
            leftIdx--;

            if (leftK == k) {
                break;
            }
            if (leftIdx < 0) {
                break;
            }
        }

        // Set team to "k" students on right
        rightIdx = bestIdx+1;
        rightK = 0;
        while (true) {
            if (teams[rightIdx] == 0) {
                teams[rightIdx] = team;
                rightK++;
            }
            rightIdx++;

            if (rightK == k) {
                break;
            }
            if (rightIdx >= n) {
                break;
            }
        }

        if (team == 1) {
            team = 2;
        } else {
            team = 1;
        }
    }

    for (int i = 0; i < teams.size(); i++) {
        cout << teams[i] << "";
    }

    return 0;
}
