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



void TreeDiameterAndCircumference(int tt)
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto bfs = [&](int source, int& depth) -> int
    {
        queue<int> q;
        q.push(source);
        vector<bool> visited(n);
        visited[source] = true;
        int end = source;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                int node = q.front();
                q.pop();
                for (int nei : adj[node])
                {
                    if (!visited[nei])
                    {
                        q.push(nei);
                        end = nei;
                        visited[nei] = true;
                    }
                }
            }
            depth++;
        }
        return end;
    };

    int depth = -1;

    int end = bfs(0, depth);

    int ans = -1;

    bfs(end, ans);

    //Circumference

    cout << 3 * ans;
}