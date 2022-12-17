#include <iostream>
#include <vector>
#include <set>

using namespace std;

const size_t MAX_NUM = 1'000'000'000'000;

struct Edge
{
    explicit Edge(const vector<int>& edge) : from(edge[0]), to(edge[1]), weight(edge[2]) {}
    explicit Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}

    int from;
    int to;
    int weight;

    friend ostream& operator<<(ostream& os, const Edge& edge);
};

ostream& operator<<(ostream& os, const Edge& edge)
{
    cout << "(" << edge.from << ", " << edge.to << ", " << edge.weight << ")";
    return os;
}

vector<size_t> Dijkstra(int n, int src, const vector<vector<Edge>>& graph)
{
    vector<size_t> distances (n, MAX_NUM);
    distances[src] = 0;

    set<pair<size_t, int>> verticesSortedByCurrDistances;
    verticesSortedByCurrDistances.insert({distances[src], src});

    while (!verticesSortedByCurrDistances.empty())
    {
        auto vertex = verticesSortedByCurrDistances.begin()->second;
        verticesSortedByCurrDistances.erase(verticesSortedByCurrDistances.begin());

        for (const auto& edge : graph[vertex])
        {
            if (distances[edge.from] + edge.weight >= distances[edge.to]) continue;
            verticesSortedByCurrDistances.erase({distances[edge.to], edge.to});
            verticesSortedByCurrDistances.insert({distances[edge.from] + edge.weight, edge.to});
            distances[edge.to] = distances[edge.from] + edge.weight;
        }
    }

    return distances;
}

vector<vector<Edge>> convertToAdjList(int n, const vector<vector<int>>& edges)
{
    vector<vector<Edge>> result(n);
    for (const auto& edge : edges)
    {
        result[edge[0]].emplace_back(edge);
    }
    return result;
}

vector<vector<Edge>> revertGraph(const vector<vector<Edge>>& graph)
{
    vector<vector<Edge>> revertedGraph(graph.size());

    for (const auto& edges : graph)
    {
        for (const auto& edge : edges)
        {
            revertedGraph[edge.to].emplace_back(edge.to, edge.from, edge.weight);
        }
    }

    return revertedGraph;
}

void printDistances(int n, vector<size_t> distances)
{
    for (int i = 0; i < n; ++i)
    {
        cout << i << ": " << distances[i] << "\n";
    }
}

class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<Edge>> graph = convertToAdjList(n, edges);
        auto revertedGraph = revertGraph(graph);

        auto distancesFromSrc1 = Dijkstra(n, src1, graph);
        auto distancesFromSrc2 = Dijkstra(n, src2, graph);
        auto distancesFromDst = Dijkstra(n, dest, revertedGraph);

        size_t result = MAX_NUM;
        for (int i = 0; i < n; ++i)
        {
            result = min(result, distancesFromSrc1[i] + distancesFromSrc2[i] + distancesFromDst[i]);
        }

        return result < MAX_NUM ? (long long)result : -1;
    }
};
