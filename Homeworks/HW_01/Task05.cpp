#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int target;
    int counter = 0;
    cin >> target;

    vector<int> vec;
    vector<int> vec2;
    vector<string> expl;

    std::vector<int>::iterator it;
    string s;

    for (int i = 0; i <= 20; i++)
    {
        // add from 1 to 20
        it = find(vec.begin(), vec.end(), i);
        vec.push_back(i);


        // i x 2
        it = find(vec.begin(), vec.end(), i*2);

        if (i != 0) {
            vec.push_back(i*2);
            vec2.push_back(i*2);
        }

        // i x 3
        it = find(vec.begin(), vec.end(), i*3);
        if (i != 0) {
            vec.push_back(i*3);
        }
    }

    vec.push_back(25);
    vec.push_back(50);
    vec2.push_back(50);

    for (int i=0; i<vec2.size(); i++) {
        for (int j=0; j<vec.size(); j++) {
            for (int k=0; k<vec.size(); k++) {
                if ((vec2.at(i) + vec.at(j) + vec.at(k)) == target) {
                    counter++;
                }
            }
        }
    }

    for (int i=0; i<vec2.size(); i++) {
        if (vec2.at(i) == target) {
            counter++;
        }
    }

    for (int i=0; i<vec2.size(); i++) {
        for (int j=0; j<vec.size(); j++) {
            if ((vec2.at(i) + vec.at(j) ) == target) {
                counter++;
            }
        }
    }

    cout << counter;

    return 0;
}
