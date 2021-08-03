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

struct LCA
{
    vector<int> height, first, euler, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>>& adj, int root = 0)
    {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        visited.assign(n, false);
        dfs(adj, root, 0);
        int m = euler.size();
        segtree.resize(4 * m);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>>& adj, int node, int h = 0)
    {
        height[node] = h;
        visited[node] = true;
        euler.push_back(node);
        first[node] = euler.size() - 1;
        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                dfs(adj, neighbour, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int v, int tl, int tr)
    {
        if (tl == tr)
        {
            segtree[v] = euler[tl];
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(2 * v, tl, tm);
            build(2 * v + 1, tm + 1, tr);
            int l = segtree[2 * v];
            int r = segtree[2 * v + 1];
            segtree[v] = height[l] < height[r] ? l : r;
        }
    }

    int query(int v, int tl, int tr, int l, int r)
    {
        if (tl > r || tr < l)
        {
            return -1;
        }
        if (l == tl && tr == r)
        {
            return segtree[v];
        }
        int tm = (tl + tr) / 2;
        int left = query(2 * v, tl, tm, l, min(tm, r));
        int right = query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
        if (left == -1)
        {
            return right;
        }
        if (right == -1)
        {
            return left;
        }
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v)
    {
        int left = first[u];
        int right = first[v];
        if (left > right)
        {
            swap(left, right);
        }
        int ans = query(1, 0, euler.size() - 1, left, right);
        return ans;
    }

};

void findLCA(int tt)
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int neighbour;
            cin >> neighbour;
            neighbour--;
            adj[i].push_back(neighbour);
        }
    }

    LCA* obj = new LCA(adj, 0);

    int q;
    cin >> q;
    cout << "Case " << tt << ":" << "\n";
    for (int qq = 0; qq < q; qq++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        int ans = obj->lca(u, v);
        cout << ans + 1 << "\n";
    }

}