class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        int maxNode = getMaxNode(edges);
        parents.resize(maxNode + 1);

        // step 1: find node with input degree equal to 2 if exists
        resetParents();
        vector<vector<int>> candidates;
        for (auto &edge: edges) {
            if (parents[edge[1]] == edge[1]) parents[edge[1]] = edge[0];
            else {
                candidates = {
                        {parents[edge[1]], edge[1]},
                        edge
                };
                edge[1] = DUMMY_NODE;
                break;
            }
        }

        // step 2: find cycle if exists
        resetParents();
        for (const auto &edge: edges) {
            if (find(edge[0]) == edge[1]) {
                if (candidates.empty()) return edge;
                return candidates[0];
            }
            unite(edge[0], edge[1]);
        }

        return candidates[1];
    }

private:
    int find(int node) {
        while (parents[node] != node) {
            node = parents[node];
        }
        return node;
    }

    void unite(int first, int second) {
        parents[find(second)] = first;
    }

    void resetParents() {
        for (int i = 0; i < parents.size(); ++i) {
            parents[i] = i;
        }
    }

private:
    static int getMaxNode(const vector<vector<int>> &edges) {
        int max = 1;

        for (const auto &edge: edges) {
            if (edge[0] > max) max = edge[0];
            if (edge[1] > max) max = edge[1];
        }

        return max;
    }

private:
    vector<int> parents;
    const int DUMMY_NODE = 0;
};
