#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    vector< vector<int> > matrix;

public:

    Graph(int n) {
        matrix.resize(n);

        for (int i = 0; i < n; i++) {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    void connect(int from, int to, int weight) {
        matrix[from][to] = weight;
        matrix[to][from] = weight;
    }

    void print() const {
        for (int i = 0; i < matrix.size(); i++) {
            cout << i << " -> ";
            for (int j = 0; j < matrix.size(); j++) {
                if (matrix[i][j] != 0) {
                    cout << j << "(" << matrix[i][j] << "), ";
                }
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
