//Query to identify the number of distinct alphabets in a range. Also update the value at a given index.



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

vector<vector<bool>> tree(4 * maxN, vector<bool>(26, false));

string s;

vector<bool> combine(vector<bool> a, vector<bool> b)
{
    vector<bool> ans = a;
    for (int i = 0; i < 26; i++)
    {
        ans[i] = (ans[i] | b[i]);
    }
    return ans;
}

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        vector<bool> st(26, false);
        st[s[tl] - 'a'] = true;
        tree[v] = st;
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
    }
}

vector<bool> value(int v, int tl, int tr, int l, int r)
{
    if (l > r)
    {
        return vector<bool>(26, false);
    }
    int tm = (tl + tr) / 2;
    if (l == tl && r == tr)
    {
        return tree[v];
    }
    return combine(value(2 * v, tl, tm, l, min(tm, r)), value(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
}

void update(int v, int tl, int tr, int pos, char val)
{
    if (tl == tr)
    {
        vector<bool> st(26, false);
        st[val - 'a'] = true;
        tree[v] = st;
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            update(2 * v, tl, tm, pos, val);
        }
        else
        {
            update(2 * v + 1, tm + 1, tr, pos, val);
        }
        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
    }
}

void solve(int tt)
{
    cin >> s;
    int n = s.size();
    int q;
    cin >> q;

    build(1, 0, n - 1);

    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int pos;
            char ch;
            cin >> pos >> ch;
            pos--;
            update(1, 0, n - 1, pos, ch);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            vector<bool> ans = value(1, 0, n - 1, l, r);
            int count = 0;
            for (int i = 0; i < 26; i++)
            {
                count += ans[i];
            }
            cout << count << "\n";
        }
    }

}