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

int l;

vector<vector<int>> up;

void TreeAncestor(int n, vector<int>& parent)
{
    l = ceil(log2(n));
    up.resize(n, vector<int>(l + 1, -1));
    for (int i = 0; i < (int)parent.size(); i++)
    {
        int child = i;
        up[child][0] = parent[i];
    }
    for (int i = 0; i < n; i++)
    {
        int node = i;
        for (int height = 1; height <= l; height++)
        {
            int chk = up[node][height - 1];
            if (chk < 0)
            {
                break;
            }
            up[node][height] = up[up[node][height - 1]][height - 1];
        }
    }
}

int getKthAncestor(int node, int k)
{
    int ans = -1;
    for (int i = l; i >= 0; i--)
    {
        if (node == -1)
        {
            ans = -1;
            break;
        }
        if (k >= (1 << i))
        {
            k -= (1 << i);
            node = up[node][i];
            ans = node;
        }
    }
    return ans;
}