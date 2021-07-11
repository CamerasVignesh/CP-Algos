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
//#include <bits/stdc++.h>

using namespace std;



class compareClass
{
public:
    bool operator() (pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
    {
        return a.first > b.first;
    }
};

int minimumEffortPath(vector<vector<int>>& heights)
{
    int h = heights.size();
    int w = heights[0].size();
    const int INF = 1e9 + 5;
    map<pair<int, int>, bool> visited;
    map<pair<int, int>, vector<pair<pair<int, int>, int>>> adj;
    map<pair<int, int>, int> dist;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compareClass> q;
    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col < w; col++)
        {
            dist[make_pair(row, col)] = INF;
            visited[make_pair(row, col)] = false;
        }
    }
    vector<pair<int, int>> dirs = { make_pair(0,1), make_pair(0,-1), make_pair(1,0), make_pair(-1,0) };
    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col < w; col++)
        {
            pair<int, int> point = make_pair(row, col);
            for (pair<int, int> dir : dirs)
            {
                int newRow = row + dir.first;
                int newCol = col + dir.second;
                if (newRow >= 0 && newRow < h && newCol >= 0 && newCol < w)
                {
                    pair<int, int> neighbour = make_pair(newRow, newCol);
                    int diff = abs(heights[row][col] - heights[newRow][newCol]);
                    adj[point].push_back(make_pair(neighbour, diff));
                }
            }
        }
    }

    dist[make_pair(0, 0)] = 0;
    q.push(make_pair(0, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<int, pair<int, int>> node = q.top();
        q.pop();
        pair<int, int> parent = node.second;
        int cost = node.first;
        if (!visited[parent])
        {
            visited[parent] = true;
            for (pair<pair<int, int>, int> entry : adj[parent])
            {
                pair<int, int> neighbour = entry.first;
                int neighbourCost = entry.second;
                int nextPossible = neighbourCost;
                if (dist[neighbour] > max(nextPossible, dist[parent]))
                {
                    dist[neighbour] = max(nextPossible, dist[parent]);
                    q.push(make_pair(nextPossible, neighbour));
                }
            }
        }
    }
    return dist[make_pair(h - 1, w - 1)];
}