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
    Node * head =  nullptr;
    Node * tail = nullptr;
public:
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

    void copyLinkedList(const LinkedList & obj) {
        Node * temp = obj.head;

        while (temp != nullptr) {
            push_back(temp->data);
            temp = temp->next;
        }
    }

    LinkedList & operator=(const LinkedList & obj) {
        if (this != &obj) {
            freeMemory();
            copyLinkedList(obj);
        }
        return *this;
    }

    LinkedList(const LinkedList & obj) {
        copyLinkedList(obj);
    }

    void push_front(int number) {
        Node * newHead = new Node(number, head);
        head = newHead;
        if (tail == nullptr) {
            tail = head;
        }
    }

    void push_back(int number) {
        if (head == nullptr) {
            head = new Node(number);
            tail = head;
        } else {
            tail->next = new Node(number);
            tail = tail->next;
        }
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
            cerr << "List is empty! Can not do a peek_front()!" << endl;
            return -1;
        }
    }

    int peek_back() {
        if (tail != nullptr) {
            return tail->data;
        } else {
            cerr << "List is empty! Can not do a peek_back()!" << endl;
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
            }

            Node * temp = head;

            while (temp->next->next != nullptr) {
                temp = temp->next;
            }

            delete tail;
            temp->next = nullptr;
            tail = temp;
        } else {
            cerr << "List is empty! Can not do a pop_back()!" << endl;
        }
    }

    void insert(int number, int position) {
        if (position == 0) {
            push_back(number);
            return;
        }

        if (head == nullptr) {
            cerr << "List is empty!" << endl;
            return;
        }

        Node * current = head;
        Node * previous = nullptr;

        for (int i = 0; i < position; i++) {
            if (current != nullptr) {
                previous = current;
                current = current->next;
            } else {
                cerr << "Invalid position!" << endl;
                return;
            }
        }

        previous->next = new Node(number, current);

        if (tail == previous) {
            tail = previous->next;
        }
    }

    int get(int position) {
        if (head == nullptr) {
            cerr << "List is empty!" << endl;
            return -1;
        }

        Node * current = head;

        for (int i = 0; i < position; i++) {
            if (current != nullptr) {
                current = current->next;
            } else {
                cerr << "Invalid position!" << endl;
                return -1;
            }
        }

        return current->data;
    }

    void remove(int position) {
        if (head == nullptr) {
            cerr << "List is empty!" << endl;
            return;
        }

        Node * current = head;
        Node * previous = nullptr;

        for (int i = 0; i < position; i++) {
            if (current != nullptr) {
                previous = current;
                current = current->next;
            } else {
                cerr << "Invalid position!" << endl;
                return;
            }
        }

        previous->next = current->next;

        if (current == tail) {
            tail = previous;
        }

        delete current;
    }

};


int main() {

    LinkedList l;

    l.pop_front();

    l.push_back(0);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    l.print();

    l.insert(20, 3);

    l.print();

    l.pop_back();
    l.pop_front();

    l.print();

    l.remove(2);

    l.print();

    return 0;
}
