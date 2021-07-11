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



vector<int> dp;

vector<vector<int>> edges;

int dfs(int node)
{
    if (dp[node] != 0)
    {
        return dp[node];
    }
    int maxDepth = 0;
    for (int neighbour : edges[node])
    {
        maxDepth = max(maxDepth, 1 + dfs(neighbour));
    }
    dp[node] = max(dp[node], maxDepth);
    return dp[node];
}

int longestPath(int tt)
{
    int n, m;
    cin >> n >> m;
    dp.resize(n, 0);
    edges.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dfs(i));
    }
    return ans;
}