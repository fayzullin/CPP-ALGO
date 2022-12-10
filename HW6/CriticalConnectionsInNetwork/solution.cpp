#include <vector>

using namespace std;

struct Edge {
    explicit Edge(const vector<int> &edge) : from(edge[0]), to(edge[1]) {}

    explicit Edge(int from, int to) : from(from), to(to) {}

    int from;
    int to;
};

vector <vector<Edge>> convertToAdjList(int n, const vector <vector<int>> &edges) {
    vector <vector<Edge>> result(n);
    for (const auto &edge: edges) {
        result[edge[0]].emplace_back(edge);
        result[edge[1]].emplace_back(edge[1], edge[0]);
    }
    return result;
}

class Solution {
public:
    vector <vector<int>> criticalConnections(int n, vector <vector<int>> &connections) {
        vector <vector<Edge>> adjList = convertToAdjList(n, connections);
        resetDFS(n);
        DFS(0, -1, adjList);
        return bridges;
    }

private:
    void DFS(int vertex, int parent, vector <vector<Edge>> &adjList) {
        in[vertex] = timer++;
        fup[vertex] = in[vertex];
        visited[vertex] = true;

        for (const auto &edge: adjList[vertex]) {
            if (edge.to == parent) continue;

            // ancestors achievable from `vertex` itself
            if (visited[edge.to]) {
                fup[vertex] = min(fup[vertex], in[edge.to]);
            }
                // ancestors achievable from subtree of `vertex`
            else {
                DFS(edge.to, vertex, adjList);
                fup[vertex] = min(fup[vertex], fup[edge.to]);
                if (fup[edge.to] == in[edge.to]) {
                    vector<int> bridge = {vertex, edge.to};
                    bridges.emplace_back(bridge);
                }
            }
        }
    }

    void resetDFS(int n) {
        timer = 0;
        in.resize(n, 0);
        fup.resize(n, 0);
        visited.resize(n, false);
    }

    int timer;
    vector<int> in;                 // in[v] contains time of first visit to vertex v
    vector<int> fup;                // fup[v] contains time of visit to the "highest" ancestor achievable from subtree of vertex v
    vector<bool> visited;
    vector <vector<int>> bridges;
};