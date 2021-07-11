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

const int maxN = 1e5 + 5;

vector<pair<int, int>> tree(4 * maxN);

vector<int> A;

int GCDBetweenLimits(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return GCDBetweenLimits(b, a % b);
}

pair<int, int> combineGCDBetweenLimits(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return make_pair(a.first, a.second + b.second);
    }
    if (a.first == 0)
    {
        return b;
    }
    if (b.first == 0)
    {
        return a;
    }
    int hcf = GCDBetweenLimits(a.first, b.first);
    if (hcf == a.first)
    {
        return a;
    }
    else if (hcf == b.first)
    {
        return b;
    }
    else
    {
        return make_pair(hcf, 0);
    }
}

void buildGCDBetweenLimits(int v, int tl, int tr)
{
    if (tl == tr)
    {
        tree[v] = make_pair(A[tl], 1);
    }
    else
    {
        int tm = (tl + tr) / 2;
        buildGCDBetweenLimits(2 * v, tl, tm);
        buildGCDBetweenLimits(2 * v + 1, tm + 1, tr);
        tree[v] = combineGCDBetweenLimits(tree[2 * v], tree[2 * v + 1]);
    }
}

pair<int, int> getGCDBetweenLimits(int v, int tl, int tr, int l, int r)
{
    if (l > r)
    {
        return make_pair(0, 0);
    }
    int tm = (tl + tr) / 2;
    if (l == tl && r == tr)
    {
        return tree[v];
    }
    return combineGCDBetweenLimits(getGCDBetweenLimits(2 * v, tl, tm, l, min(tm, r)), getGCDBetweenLimits(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
}

//void update(int v, int tl, int tr, int pos, char val)
//{
//    if (tl == tr)
//    {
//        vector<bool> st(26, false);
//        st[val - 'a'] = true;
//        tree[v] = st;
//    }
//    else
//    {
//        int tm = (tl + tr) / 2;
//        if (pos <= tm)
//        {
//            update(2 * v, tl, tm, pos, val);
//        }
//        else
//        {
//            update(2 * v + 1, tm + 1, tr, pos, val);
//        }
//        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
//    }
//}

void solveGCDBetweenLimits(int tt)
{
    int n;
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int q;
    cin >> q;

    buildGCDBetweenLimits(1, 0, n - 1);

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        pair<int, int> hcf = getGCDBetweenLimits(1, 0, n - 1, l, r);
        cout << r - l + 1 - hcf.second << "\n";
    }

}