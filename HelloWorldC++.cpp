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

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

void primes(int n)
{    
    vector<int> primeValues;
    vector<bool> primes(n + 1);
    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
        {
            primeValues.push_back(i);
        }
    }
}

pair<int, vector<string>> input()
{
    int n = 5;
    int maxX = 1002;
    vector<string> numbers;
    for (int i = 0; i < n; i++)
    {
        int val = (rand() % maxX) + 1;
        numbers.push_back(to_string(val));
    }
    return make_pair(n, numbers);
}




void solve(int tt)
{
    string a, b;
    cin >> a >> b;
    string ans = "";
    int m, n;    
    m = a.size();
    n = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        if (a[i] == b[j])
        {
            ans += a[i];
            i++;
            j++;
        }
        else if (dp[i + 1][j] > dp[i][j + 1])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    //reverse(ans.begin(), ans.end());
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for (int i = 1; i<= t; i++)
    {
        solve(i);
    }       
}