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

using namespace std;

void knapsack(int tt)
{
    long long N, W;
    cin >> N >> W;
    vector<vector<long long>> dp(N + 1, vector<long long>(W + 1));
    vector<long long> w(N);
    vector<long long> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i <= W; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[N][W];
}