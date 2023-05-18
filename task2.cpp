#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int source, destination, weight;

    Edge(int src, int dest, int w) : source(src), destination(dest), weight(w) {}
};

class Graph {
private:
    int numVertices;
    vector<vector<pair<int, int>>> adjacencyList;

public:
    Graph(int vertices) : numVertices(vertices) {
        adjacencyList.resize(numVertices);
    }

    void addEdge(int src, int dest, int weight) {
        adjacencyList[src].push_back(make_pair(dest, weight));
        adjacencyList[dest].push_back(make_pair(src, weight));
    }

    int findMinimumSpanningTree() {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(numVertices, false);
        int minWeight = 0;

        int startVertex = 0;

        pq.push(make_pair(0, startVertex));

        while (!pq.empty()) {
            int currentVertex = pq.top().second;
            int currentWeight = pq.top().first;
            pq.pop();

            if (visited[currentVertex])
                continue;

            visited[currentVertex] = true;

            minWeight += currentWeight;

            for (auto neighbor : adjacencyList[currentVertex]) {
                int neighborVertex = neighbor.first;
                int neighborWeight = neighbor.second;

                if (!visited[neighborVertex])
                    pq.push(make_pair(neighborWeight, neighborVertex));
            }
        }

        return minWeight;
    }
};

int main() {
    int numVertices = 4;

    Graph graph(numVertices);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 4);
    graph.addEdge(2, 3, 5);

    int minWeight = graph.findMinimumSpanningTree();

    cout << "Weight of minimum spanning tree: " << minWeight << endl;

    return 0;
}
