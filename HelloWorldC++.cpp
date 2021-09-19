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


void solve()
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

    int target = n+1;
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

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}