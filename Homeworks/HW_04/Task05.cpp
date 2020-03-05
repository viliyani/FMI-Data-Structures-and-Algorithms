#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;

    Node (int data, Node * next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

class LinkedList {
private:

public:
    Node * head =  nullptr;
    Node * tail = nullptr;
    int size = 0;

    LinkedList() = default;

    void freeMemory() {
        Node * i = head;
        Node * next;

        while (i != nullptr) {
            next = i->next;
            delete i;
            i = next;
        }

        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        freeMemory();
    }

    void push_front(int number) {
        Node * newHead = new Node(number, head);
        head = newHead;
        if (tail == nullptr) {
            tail = head;
        }
        size++;
    }

    void push_back(int number) {
        if (head == nullptr) {
            head = new Node(number);
            tail = head;
        } else {
            tail->next = new Node(number);
            tail = tail->next;
        }
        size++;
    }

    void print() const {
        Node * temp;

        temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    int peek_front() {
        if (head != nullptr) {
            return head->data;
        } else {
            return -1;
        }
    }

    int peek_back() {
        if (tail != nullptr) {
            return tail->data;
        } else {
            return -1;
        }
    }

    void pop_front() {
        if (head != nullptr) {
            Node * temp = head;

            if (head == tail) {
                tail = nullptr;
            }

            head = head->next;
            delete temp;
            size--;
        } else {
            cerr << "List is empty! Can not do a pop_front()!" << endl;
        }
    }

    void pop_back() {
        if (head != nullptr) {
            if (head == tail) {
                delete head;

                head = nullptr;
                tail = nullptr;
            } else {
                Node * temp = head;

                while (temp->next->next != nullptr) {
                    temp = temp->next;
                }

                delete tail;
                temp->next = nullptr;
                tail = temp;
            }
            size--;
        } else {
            cerr << "List is empty! Can not do a pop_back()!" << endl;
        }
    }

    void reverse() {
        Node * curr = head;
        Node * prev = nullptr;
        Node * next = nullptr;

        tail = head;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

};

void isPossible(LinkedList & l1, int N) {
    LinkedList l2;
    LinkedList l3;

    int nextNum = 1;
    bool flag = true;

    while (true) {
        if (l2.size == 0) {
            if (l1.size == 0) {
                if (l3.tail->data != N) {
                    flag = false;
                }
                break;
            } else {

                if (l1.tail->data == nextNum) {
                    l3.push_back(l1.tail->data);
                    l1.pop_back();
                    nextNum++;
                } else {
                    l2.push_back(l1.tail->data);
                    l1.pop_back();
                }
            }
            continue;
        } else {
            if (l2.tail->data == nextNum) {
                l3.push_back(l2.tail->data);
                l2.pop_back();
                nextNum++;
            } else {
                if (l1.size == 0) {
                    flag = false;
                    break;
                } else {
                    if (l1.tail->data == nextNum) {
                        l3.push_back(l1.tail->data);
                        l1.pop_back();
                        nextNum++;
                    } else {
                        l2.push_back(l1.tail->data);
                        l1.pop_back();
                    }
                }
            }
            continue;
        }
    }

    if (flag) {
        cout << "yes\n";
        //l3.reverse();
        //cout << endl;
        //l3.print();
    } else {
        cout << "no\n";
    }
}

int main() {
    int N, Q, temp;

    cin >> Q;

    // Requests
    for (int r = 0; r < Q; r++) {
        cin >> N;

        LinkedList l1;

        for (int i = 0; i < N; i++) {
            cin >> temp;
            l1.push_back(temp);
        }

        l1.reverse();

        isPossible(l1, N);
    }

    return 0;
}
