/* Implement program Count all possible Paths between two Vertices.
Statement Count the total number of ways or paths that exist 
between two vertices in a directed graph. These paths don’t contain 
a cycle, the simple enough reason is that a cycle contains an 
infinite number of paths and hence they create a problem
Input: Count paths between A and E
Output: Total paths between A and E are 4
*/

#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int src, int dst);
    int countPaths(int src, int dst);

private:
    int vertices;
    vector<vector<int>> adjList;
    void countPathsUtil(int src, int dst, int& pathCount);
};

Graph::Graph(int vertices) : vertices(vertices), adjList(vertices) {}

void Graph::addEdge(int src, int dst) {
    adjList[src].push_back(dst);
}

int Graph::countPaths(int src, int dst) {
    int pathCount = 0;
    countPathsUtil(src, dst, pathCount);
    return pathCount;
}

void Graph::countPathsUtil(int src, int dst, int& pathCount) {
    if (src == dst) {
        pathCount++;
        return;
    }
    for (int neighbor : adjList[src]) {
        countPathsUtil(neighbor, dst, pathCount);
    }
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 4);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 1);
    g.addEdge(3, 2);

    cout << "Number of paths from 0 to 4: " << g.countPaths(0, 4) << endl;
    return 0;
}
