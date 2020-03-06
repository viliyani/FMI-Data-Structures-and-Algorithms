#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

void print(set<int> s) {
    for (auto i = s.begin(); i != s.end(); i++) {
        cout << *i << ", ";
    }
    cout << "\n";
}

int main() {
    // Initialize set
    set<int> s;

    int size = 10;

    // Add values
    for (int i = 0; i < size; i++) {
        s.insert(i);
    }

    // Insert element
    s.insert(-1);

    // Erase element
    s.erase(-1);

    // Count elements
    int countFives = s.count(5);

    // Find if an element exists
    auto five = s.find(5);
    if (five == s.end()) {
        cout << "5 is not found \n";
    } else {
        cout << "Found 5 -> " << *five << "\n";
    }

    print(s);

    return 0;
}
