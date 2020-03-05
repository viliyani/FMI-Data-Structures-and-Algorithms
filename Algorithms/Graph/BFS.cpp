#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

struct Node {
    list<int> neighbours;

    bool hasNeighbour(int index) {
        for (auto neighbour : neighbours) {
            if (neighbour == index) {
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

    void _BFS(int start, vector<bool> & visited) {
        queue<int> nextToProcess;
        nextToProcess.push(start);
        visited[start] = true;

        while (!nextToProcess.empty()) {
            int current = nextToProcess.front();
            nextToProcess.pop();

            cout << current << ", ";

            for (auto neighbour : nodes[current].neighbours) {
                if (!visited[neighbour]) {
                    nextToProcess.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

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

    void BFS(int start) {
        vector<bool> visited;
        visited.resize(nodes.size(), false);
        _BFS(start, visited);
    }

};

int main() {
    Graph g(4);

	g.connect(0, 1);
	g.connect(1, 0);
	g.connect(1, 2);
	g.connect(1, 3);
	g.connect(2, 1);
	g.connect(3, 1);
	g.connect(3, 2);

	g.BFS(3);

    return 0;
}
