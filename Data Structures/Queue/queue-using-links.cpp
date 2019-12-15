#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * previous = nullptr;

    Node(int data, Node * previous = nullptr) {
        this->data = data;
        this->previous = previous;
    }
};

class Queue {
private:
    Node * front = nullptr;
    Node * back = nullptr;
public:
    Queue() = default;

    void copyQueue(const Queue & obj) {
        Node * temp = obj.front;

        while (temp != nullptr) {
            push(temp->data);
            temp = temp->previous;
        }
    }

    void freeMemory() {
        while (front != nullptr) {
            Node * previous = front->previous;
            delete front;
            front = previous;
        }
    }

    Queue(const Queue & obj) {
        copyQueue(obj);
    }

    Queue & operator=(const Queue & obj) {
        if (this != &obj) {
            freeMemory();
            copyQueue(obj);
        }

        return *this;
    }

    ~Queue() {
        freeMemory();
    }

    void push(int number) {
        if (isEmpty()) {
            front = new Node(number);
            back = front;
        } else {
            back->previous = new Node(number);
            back = back->previous;
        }
    }

    void pop() {
        if (!isEmpty()){
            Node * oldFront = front;
            front = front->previous;
            delete oldFront;
        } else {
            cerr << "Queue is empty!" << endl;
        }
    }

    int peek() const {
        if (!isEmpty()) {
            return front->data;
        } else {
            cerr << "Queue is empty!" << endl;
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }

};

int main () {
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    while (!q.isEmpty()) {
        cout << q.peek() << endl;
        q.pop();
    }

    return 0;
}
