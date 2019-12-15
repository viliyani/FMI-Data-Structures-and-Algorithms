#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> data;
public:
    void push(int number) {
        data.push_back(number);
    }

    void pop() {
        data.pop_back();
    }

    int peek() const {
        if (data.size() > 0) {
           return data.back();
        } else {
            cerr << "Stack is empty!" << endl;
        }
    }

    bool isEmpty() const {
        return data.size() == 0;
    }

};

int main () {
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while (!s.isEmpty()) {
        cout << s.peek() << endl;
        s.pop();
    }

    return 0;
}
