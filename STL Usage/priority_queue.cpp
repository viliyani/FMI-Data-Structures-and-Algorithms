#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

struct Pair {
    int priority;
    string value;

    bool operator<(const Pair & rhs) const {
        return priority < rhs.priority;
    }
};

void print(priority_queue<Pair> s) {
    priority_queue<Pair> copy = s;

    while (!copy.empty()) {
        cout << copy.top().value << ", ";
        copy.pop();
    }
    cout << "\n";
}

int main() {
    priority_queue<Pair> s;

    s.push({5, "I have middle priority"});
    s.push({18, "I have low priority"});
    s.push({2, "I have high priority"});

    print(s);

    return 0;
}
