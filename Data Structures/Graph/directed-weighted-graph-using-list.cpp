#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Pair {
    int index;
    int weight;
};

struct Node {
    list<Pair> neighbours;

    bool hasNeighbour(int index) {
        for (auto neighbour : neighbours) {
            if (neighbour.index == index) {
                return true;
            }
        }
        return false;
    }

    void addNeighbour(int index, int weight) {
        neighbours.push_back(Pair{index, weight});
    }
};

class Graph {
private:
    vector<Node> nodes;

public:
    Graph(int nodesCount = 0) {
        nodes.resize(nodesCount);
    }

    void connect (int from, int to, int weight) {
        if (!nodes[from].hasNeighbour(to)) {
            nodes[from].addNeighbour(to, weight);
        }
    }

    void print() const {
        for (int i = 0; i < nodes.size(); i++) {
            cout << i << ": ";
            for (auto neighbour : nodes[i].neighbours) {
                cout << neighbour.index << "(" << neighbour.weight << "), ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);

	g.connect(0, 1, 5);
	g.connect(0, 2, 6);
	g.connect(1, 2, 2);
	g.connect(1, 3, 7);

	g.print();

    return 0;
}
