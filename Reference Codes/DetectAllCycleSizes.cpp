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
#include <random>

using namespace std;

using ll = long long;

const vector<int> dx = { 0, 1, 0, -1 };

const vector<int> dy = { 1, 0, -1, 0 };

const int MOD = 1e9 + 7;

const int INF = 1e9 + 5;

int dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[node] = true;
    for (int nei : adj[node])
    {
        if (!visited[nei])
        {
            return 1 + dfs(nei, adj, visited);
        }
    }
    return 1;
}

void DetectAllCycleSizes(int tt)
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n);
    for (int i = 0; i < n; i++)
    {
        if ((int)adj[i].size() != 2)
        {
            cout << "NO\n";
            return;
        }
        if (!visited[i])
        {
            int cycle = dfs(i, adj, visited);
            if (cycle % 2 == 1)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}