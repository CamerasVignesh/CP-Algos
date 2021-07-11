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
//#include <bits/stdc++.h>

using namespace std;


void solveQ1(int tt)
{
    vector<vector<long long>> a(3, vector<long long>(3, 0));
    cin >> a[0][0] >> a[0][1] >> a[0][2] >> a[1][0] >> a[1][2] >> a[2][0] >> a[2][1] >> a[2][2];
    long long ans = 0;
    if (2 * a[0][1] == a[0][0] + a[0][2])
    {
        ans++;
    }
    if (2 * a[2][1] == a[2][0] + a[2][2])
    {
        ans++;
    }
    if (2 * a[1][0] == a[0][0] + a[2][0])
    {
        ans++;
    }
    if (2 * a[1][2] == a[0][2] + a[2][2])
    {
        ans++;
    }
    map<long long, long long> mp;
    mp[a[0][0] + a[2][2]]++;
    mp[a[0][1] + a[2][1]]++;
    mp[a[0][2] + a[2][0]]++;
    mp[a[1][2] + a[1][0]]++;
    long long curr = 1;
    for (const auto& it : mp)
    {
        if (it.second > curr)
        {
            curr = it.second;
        }
    }
    ans += curr;
    cout << "Case #" << tt << ": " << ans << "\n";
}

void solveQ2(int tt)
{
    int n;
    cin >> n;
    long long c;
    cin >> c;
    long long ans = 0;
    map<long long, long long> intervals;
    map<long long, long long> count;
    for (int i = 0; i < n; i++)
    {
        long long l;
        long long r;
        cin >> l >> r;
        intervals[l]++;
        intervals[r + 1]--;
        count[l]++;
        count[r]++;
    }
    vector<pair<long long, long long>> values;
    for (const auto& it : intervals)
    {
        values.emplace_back(it.second, it.first);
    }
    sort(values.begin(), values.end());
    for (long long i = 0; i < c; i++)
    {

    }
}

void solveQ3(int tt)
{
    long long n, m;
    cin >> n >> m;
    set<long long> values;
    for (long long i = 0; i < n; i++)
    {
        long long l, r;
        cin >> l >> r;
        for (long long j = l; j <= r; j++)
        {
            values.insert(j);
        }
    }
    vector<long long> ans(m);
    for (long long i = 0; i < m; i++)
    {
        long long s;
        cin >> s;
        auto it = values.lower_bound(s);
        auto it2 = it;
        if (it == values.end())
        {
            auto it3 = values.end();
            --it3;
            ans[i] = *it3;
        }
        else
        {
            if (it != values.begin())
            {
                --it2;
            }
            if (*it - s >= s - *it2)
            {
                ans[i] = *it2;
                values.erase(it2);
            }
            else
            {
                ans[i] = *it;
                values.erase(it);
            }
        }
    }
    cout << "Case #" << tt << ": ";
    for (long long i = 0; i < m; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

vector<pair<long long, long long>> sums;
vector<long long> a;

pair<long long, long long> combineQ4(pair<long long, long long> a, pair<long long, long long> b)
{
    return make_pair(a.first + b.first, a.second + b.second);
}

void buildQ4(int v, int tl, int tr)
{
    if (tl == tr)
    {
        if (a[tl] < 0)
        {
            sums[v] = make_pair(abs(a[tl]), 0);
        }
        else
        {
            sums[v] = make_pair(0, a[tl]);
        }
    }
    else
    {
        int tm = (tl + tr) / 2;
        buildQ4(2 * v, tl, tm);
        buildQ4(2 * v + 1, tm + 1, tr);
        sums[v] = combineQ4(sums[2 * v], sums[2 * v + 1]);
    }
}

pair<long long, long long> getSumQ4(int v, int tl, int tr, int l, int r)
{
    if (l > r)
    {
        return make_pair(0, 0);
    }
    if (l == tl && r == tr)
    {
        return sums[v];
    }
    int tm = (tl + tr) / 2;
    return combineQ4(getSumQ4(2 * v, tl, tm, l, min(tm, r)), getSumQ4(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
}

void updateQ4(int v, int tl, int tr, int pos, long long newVal)
{
    if (tl == tr)
    {
        if (newVal < 0)
        {
            sums[v] = make_pair(abs(newVal), 0);
        }
        else
        {
            sums[v] = make_pair(0, newVal);
        }
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            updateQ4(2 * v, tl, tm, pos, newVal);
        }
        else
        {
            updateQ4(2 * v + 1, tm + 1, tr, pos, newVal);
        }
        sums[v] = combineQ4(sums[2 * v], sums[2 * v + 1]);
    }
}

int getPower(long long val, long long p)
{
    int ans = 0;
    if (val % p == 0)
    {
        while (val > 0 && val % p == 0)
        {
            ans++;
            val = val / p;
        }
        ans = -ans;
    }
    else
    {
        val = val - val % p;
        while (val > 0 && val % p == 0)
        {
            ans++;
            val = val / p;
        }
    }
    return ans;
}

void solveQ4(int tt)
{
    int n, q, p;
    cin >> n >> q >> p;
    a.clear();
    a.resize(n);
    sums.clear();
    sums.resize(4 * n);
    for (int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        int curr = getPower(temp, p);
        a[i] = curr;
    }

    buildQ4(1, 0, n - 1);

    vector<long long> ans;
    for (int qq = 0; qq < q; qq++)
    {
        int queryType;
        cin >> queryType;
        if (queryType == 1)
        {
            int pos;
            cin >> pos;
            pos--;
            long long val;
            cin >> val;
            int currVal = getPower(val, p);
            updateQ4(1, 0, n - 1, pos, currVal);
        }
        else
        {
            int s, l, r;
            cin >> s >> l >> r;
            l--;
            r--;
            pair<long long, long long> required = getSumQ4(1, 0, n - 1, l, r);
            ans.push_back(required.first * s + required.second);
        }
    }
    cout << "Case #" << tt << ": ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

