#include <iostream>
#include <climits>
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

    void findBest() {
        Node * temp;
        Node * child;

        int currentCnt = 0;
        int maxCnt = INT_MIN;
        int currentHeight = 0;
        int idx = 0;
        int maxIdx = 0;

        temp = head;

        while (temp != nullptr) {
            currentCnt = 0;
            currentHeight = temp->data;
            child = temp->next;
            //cout << "-> " << temp->data << ":" << endl;
            while (child != nullptr) {
                if (child->data > currentHeight) {
                    currentCnt += 1;
                    currentHeight = child->data;
                    //printf("(cnt:%d)", currentCnt);
                }

                //cout << child->data << " ";
                child = child->next;
            }
            //cout << endl;
            temp = temp->next;
            if (currentCnt > maxCnt) {
                maxCnt = currentCnt;
                maxIdx = idx;
            }
            idx++;
        }

        //cout << endl;
        //cout << "Answer-> " << maxIdx;
        //cout << endl;
        cout << maxIdx;
    }
};


int main() {

    int N, temp;

    cin >> N;

    LinkedList l;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        l.push_back(temp);
    }

    l.findBest();

    /*LinkedList l;
    l.push_back(6);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(7);
    l.push_back(4);
    l.push_back(5);
    l.push_back(8);
    l.push_back(11);
    l.push_back(10);
    l.push_back(9);
    l.push_back(20);*/

    return 0;
}
