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



void 1DKnapsack()
{
    vector<int> bfs(1001, INF);

    bfs[1] = 0;

    for (int i = 1; i <= 1000; i++)
    {
        for (int x = 1; x <= i; x++)
        {
            int num = i + i / x;
            if (num <= 1000)
            {
                bfs[num] = min(bfs[num], bfs[i] + 1);
            }
        }
    }

    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        weights[i] = bfs[b[i]];
    }

    vector<int> values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    vector<int> dp(k + 1);

    int sum = 0;
    for (int weight : weights)
    {
        sum += weight;
    }

    k = min(k, sum);

    for (int i = 1; i <= n; i++)
    {
        int w = weights[i - 1];
        int v = values[i - 1];

        for (int j = k - w; j >= 0; j--)
        {
            dp[j + w] = max(dp[j + w], dp[j] + v);
        }
    }

    int ans = -1;
    for (int i = 0; i <= k; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}