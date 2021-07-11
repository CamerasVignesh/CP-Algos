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

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<vector<int>> edges(numCourses);
    vector<int> indegree(numCourses, 0);
    vector<int> dist(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); i++)
    {
        vector<int> p = prerequisites[i];
        edges[p[1]].push_back(p[0]);
        indegree[p[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int neighbour : edges[node])
        {
            dist[neighbour] = max(dist[neighbour], 1 + dist[node]);
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    vector<pair<int, int>> orders;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] != 0)
        {
            return vector<int>();
        }
        orders.emplace_back(dist[i], i);
    }
    sort(orders.begin(), orders.end());
    for (int i = 0; i < numCourses; i++)
    {
        dist[i] = orders[i].second;
    }
    return dist;
}