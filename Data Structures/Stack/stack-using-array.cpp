#include <iostream>
using namespace std;

class Stack {
private:
    int capacity;
    int * data;
    int top;
public:
    Stack(int capacity) {
        this->capacity = capacity;
        this->data = new int[capacity];
        top = -1;
    }

    void copyStack(const Stack & obj) {
        this->capacity = obj.capacity;
        this->data = new int[capacity];
        this->top = obj.top;
        for (int i = 0; i <= top; i++) {
            this->data[i] = obj.data[i];
        }
    }

    void freeMemory() {
        delete[] this->data;

        this->data = nullptr;
        top = -1;
        capacity = 0;
    }

    Stack(const Stack & obj) {
        copyStack(obj);
    }

    Stack & operator=(const Stack & obj) {
        if (this != &obj) {
            freeMemory();
            copyStack(obj);
        }

        return *this;
    }

    ~Stack() {
        freeMemory();
    }

    void push(int number) {
        if (top < capacity - 1) {
            top++;
            data[top] = number;
        } else {
            cerr << "Stack is full!" << endl;
        }
    }

    void pop() {
        if (top > -1){
            top--;
        } else {
            cerr << "Stack is empty!" << endl;
        }
    }

    int peek() const {
        if (top > -1) {
            return data[top];
        } else {
            cerr << "Stack is empty!" << endl;
        }
    }

    bool isEmpty() const {
        return top == -1;
    }

};

int main () {
    Stack s(10);

    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    s.pop();

    return 0;
}
