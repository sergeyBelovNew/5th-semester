#include <iostream>
#include <random>
#include <vector>
#include <iomanip>

using namespace std;

void runTask();
unsigned int findMinPath(vector <vector<unsigned int>>& graph, const size_t& a, const size_t& b);
void showGraph(vector <vector<unsigned int>> graph);
void showShortestPath(vector <vector<unsigned int>> graph);
void fillGraph(vector <vector<unsigned int>>& graph);

int main() { 

    runTask();
    return 0;
}

void runTask() {
    size_t size;
    cout << "Input number of points(size)" << endl;
    cin >> size;

    vector <vector<unsigned int>> graph(size, vector<unsigned int>(size));

    fillGraph(graph);
    showGraph(graph);
    showShortestPath(graph);
}

unsigned int findMinPath(vector <vector<unsigned int>>& graph, const size_t& a, const size_t& b) {
    vector <vector<unsigned int>> shortestPath(graph);

    unsigned int i, j, k;
    for (k = 0; k < graph.size(); k++)
        for (i = 0; i < graph.size(); i++)
            for (j = 0; j < graph.size(); j++)
                if (shortestPath[i][k] + shortestPath[k][j] < shortestPath[i][j])
                    shortestPath[i][j] = shortestPath[i][k] + shortestPath[k][j];
    return shortestPath[a - 1][b - 1];
}

void showGraph(vector <vector<unsigned int>> graph) {
    cout << "Graph" << endl;
    for (size_t i = 0; i < graph.size(); i++) {
        cout << i + 1 << ": ";
        for (size_t j = 0; j < graph.size(); j++) {
            cout << setw(3) << graph[i][j];
        }
        cout << endl;
    }
}

void showShortestPath(vector <vector<unsigned int>> graph) {
    size_t a, b;
    cout << "Input start & end point" << endl;
    cin >> a >> b;

    cout << "Shortest path = " << findMinPath(graph, a, b) << endl;
}

void fillGraph(vector <vector<unsigned int>>& graph) {

    random_device dev;
    mt19937 random(dev());
    uniform_int_distribution<> distribution(1, 10);

    for (size_t i = 0; i < graph.size(); i++) {
        for (size_t j = i; j < graph.size(); j++) {
            if (i == j) graph[i][j] = 0;
            else {
                graph[i][j] = distribution(random);
                graph[j][i] = graph[i][j];
            }
        }
    }
}