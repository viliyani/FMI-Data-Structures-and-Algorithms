#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct Node {
    list<int> neighbours;

    bool hasNeighbour(int index) {
        for (auto i : neighbours) {
            if (i == index) {
                return true;
            }
        }
        return false;
    }

    void addNeighbour(int index) {
        neighbours.push_back(index);
    }
};

class Graph {
private:
    vector<Node> nodes;
public:
    Graph(int nodesCount = 0) {
        nodes.resize(nodesCount);
    }

    void connect(int from, int to) {
        if (!nodes[from].hasNeighbour(to)) {
            nodes[from].addNeighbour(to);
        }
    }

    void print() const {
        for (int i = 0; i < nodes.size(); i++) {
            cout << i << ": ";
            for (auto neighbour : nodes[i].neighbours) {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);

	g.connect(0, 1);
	g.connect(0, 2);
	g.connect(1, 2);
	g.connect(1, 3);

	g.print();

    return 0;
}
