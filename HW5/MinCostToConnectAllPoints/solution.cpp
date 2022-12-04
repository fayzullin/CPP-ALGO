#include <iostream>
#include <vector>

using namespace std;

const int MAX_NUM = 1'000'000'000;

struct Point
{
    Point(const vector<int>& coords) : x(coords[0]), y(coords[1]) {}

    int x;
    int y;
};

int manhattanDistance(Point p1, Point p2)
{
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

vector<vector<int>> convertToWeightedGraph(const vector<vector<int>> points)
{
    vector<vector<int>> result(points.size(), vector<int>(points.size(), MAX_NUM));

    for (int i = 0; i < points.size(); ++i)
    {
        for (int j = 0; j < points.size(); ++j)
        {
            if (i == j) continue;
            result[i][j] = manhattanDistance(points[i], points[j]);
            result[j][i] = result[i][j];
        }
    }

    return result;
}

int weightOfMST(const vector<vector<int>>& adjMatrix)
{
    int result = 0;

    int size = adjMatrix.size();
    vector<bool> addedToResult(size, false);
    vector<int> distToResult(size, MAX_NUM);

    distToResult[0] = 0; // added vertex to MST

    for (int i = 0; i < size; ++i)
    {
        // find vertex closest to current MST
        int closest = -1;
        for (int j = 0; j < size; ++j)
        {
            if (!addedToResult[j] && (closest == -1 || distToResult[j] < distToResult[closest]))
            {
                closest = j;
            }
        }
        addedToResult[closest] = true;
        result += distToResult[closest];

        // update `distToResult`
        for (int j = 0; j < size; ++j)
        {
            if (addedToResult[j]) continue;
            distToResult[j] = min(distToResult[j], adjMatrix[j][closest]);
        }
    }

    return result;
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> adjMatrix = convertToWeightedGraph(points);
        return weightOfMST(adjMatrix);
    }
};
