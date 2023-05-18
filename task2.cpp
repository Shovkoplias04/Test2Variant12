#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Структура для представлення ребра графа
struct Edge {
    int source, destination, weight;

    Edge(int src, int dest, int w) : source(src), destination(dest), weight(w) {}
};

// Клас для представлення графа
class Graph {
private:
    int numVertices;
    vector<vector<pair<int, int>>> adjacencyList;

public:
    Graph(int vertices) : numVertices(vertices) {
        adjacencyList.resize(numVertices);
    }

    // Додавання ребра у граф
    void addEdge(int src, int dest, int weight) {
        adjacencyList[src].push_back(make_pair(dest, weight));
        adjacencyList[dest].push_back(make_pair(src, weight));
    }

    // Знаходження мінімального кістякового дерева методом Прима
    int findMinimumSpanningTree() {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // Мінімальна пріоритетна черга (відсортована по вагах)
        vector<bool> visited(numVertices, false);  // Відвідані вершини
        int minWeight = 0;  // Вага мінімального кістякового дерева

        // Початкова вершина для побудови кістякового дерева
        int startVertex = 0;

        // Додавання початкової вершини до пріоритетної черги
        pq.push(make_pair(0, startVertex));

        while (!pq.empty()) {
            int currentVertex = pq.top().second;
            int currentWeight = pq.top().first;
            pq.pop();

            // Перевірка чи вершина вже відвідана
            if (visited[currentVertex])
                continue;

            // Відмітка вершини як відвіданої
            visited[currentVertex] = true;

            // Додавання ваги до мінімальної ваги дерева
            minWeight += currentWeight;

            // Додавання сусідніх вершин до черги
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
    int numVertices = 4;  // Кількість вершин у графі

    Graph graph(numVertices);

    // Додавання ребер до графа
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 4);
    graph.addEdge(2, 3, 5);

    // Знаходження ваги мінімального кістякового дерева
    int minWeight = graph.findMinimumSpanningTree();

    cout << "Weight of minimum spanning tree: " << minWeight << endl;

    return 0;
}
