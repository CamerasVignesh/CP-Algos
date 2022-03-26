#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<set>
#include<numeric>
#include<queue>
#include<cmath>
#include <stack>
#include <string>
#include <cassert>
#include <unordered_set>
#include <iomanip>

using namespace std;

struct Edge
{
    int u, v, weight;
    bool operator < (Edge const& other)
    {
        return weight < other.weight;
    }
    Edge(int U, int V, int Weight)
    {
        u = U;
        v = V;
        weight = Weight;
    }
};

int minCostConnectPoints(vector<vector<int>>& points)
{
    int ans = 0;
    int n = points.size();
    vector<Edge> edges;

    vector<Edge> edgesCreated;

    for (int u = 0; u < n; u++)
    {
        for (int v = u + 1; v < n; v++)
        {
            //The weight of each edge is the Manhattan distance between its end points
            int weight = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
            Edge edge = Edge(u, v, weight);
            edges.push_back(edge);
        }
    }

    //Sort edges by their weights
    sort(edges.begin(), edges.end());

    //In which tree each point belongs to
    vector<int> tree_id(n);

    //Getting count for each tree so that the tree with less nodes gets added to tree with more nodes 
    vector<int> count(n, 1);

    //Initially all points are their own tree
    for (int i = 0; i < n; i++)
    {
        tree_id[i] = i;
    }

    int edgesCount = 0;

    for (Edge edge : edges)
    {
        //If both end points of a edge are not part of the same tree
        if (tree_id[edge.u] != tree_id[edge.v])
        {
            //We create and add this edge
            ans += edge.weight;
            edgesCreated.push_back(edge);
            edgesCount++;
            int old_id = tree_id[edge.u], new_id = tree_id[edge.v];
            if (count[old_id] > count[new_id])
            {
                swap(old_id, new_id);
            }
            for (int i = 0; i < n; i++)
            {
                if (tree_id[i] == old_id)
                {
                    tree_id[i] = new_id;
                    count[old_id]--;
                    count[new_id]++;
                }
            }
        }
    }
    return ans;
}