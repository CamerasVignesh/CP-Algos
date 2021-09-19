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





/// <summary>
/// You go through the nodes from first to last and the future node's indegree will be decreased in the same loop. Ans is the 
/// number of cycle from 1 to n.
/// </summary>
void ModifiedKahnAlgorithm()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> edges(n, 0);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int v;
            cin >> v;
            v--;
            adj[v].push_back(i);
            edges[i]++;
        }
    }

    set<int> q;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (edges[i] == 0)
        {
            q.insert(i);
            visited[i] = true;
        }
    }

    int ans = 0;

    int target = n + 1;
    while (!q.empty())
    {
        auto it = q.lower_bound(target);
        if (it == q.end())
        {
            ans++;
            target = 0;
            continue;
        }
        int node = *it;
        q.erase(it);
        visited[node] = true;
        target = node;
        for (int neighbour : adj[node])
        {
            edges[neighbour]--;
            if (edges[neighbour] == 0)
            {
                q.insert(neighbour);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = -1;
            break;
        }
    }

    cout << ans << "\n";

}