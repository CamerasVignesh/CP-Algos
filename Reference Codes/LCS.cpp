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

string lcs(string a, string b)
{
    string lcs = "";
    int m, n;
    m = a.size();
    n = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    //dp[i][j] - contains the length of lcs till ith character of a and jth character of b. (1 indexed)
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

    int i = m;
    int j = n;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs += a[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int lengthOfLCS(string a, string b)
{
    int m, n;
    m = a.size();
    n = b.size();
    int lengthLCS = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    //dp[i][j] - contains the length of lcs till ith character of a and jth character of b. (1 indexed)
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                lengthLCS = max(lengthLCS, dp[i][j]);
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return lengthLCS;
}

int findLengthMCS(string a, string b, int i, int j)
{
    if (i == 0 || j == 0)
    {
        return 0;
    }
    if (a[i] == b[j])
    {
        return 1 + findLengthMCS(a, b, i - 1, j - 1);
    }
    else
    {
        return max(findLengthMCS(a, b, i - 1, j), findLengthMCS(a, b, i, j - 1));
    }
}

int lengthLCSWithoutMemoization(string a, string b)
{
    return findLengthMCS(a, b, 0, 0);
}