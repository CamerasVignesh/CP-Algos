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

void DetectIfAllAreEvenCycles(int tt)
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

    for (vector<int> list : adj)
    {
        if ((int)list.size() > 2)
        {
            cout << "NO\n";
            return;
        }
    }

    vector<bool> visited(n);
    vector<bool> color(n);
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            continue;
        }
        queue<int> q;
        q.push(i);
        visited[i] = true;
        color[i] = true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int nei : adj[node])
            {
                if (visited[nei])
                {
                    if (color[nei] == color[node])
                    {
                        cout << "NO\n";
                        return;
                    }
                }
                else
                {
                    color[nei] = !color[node];
                    q.push(nei);
                    visited[nei] = true;
                }
            }
        }
    }
    cout << "YES\n";
}