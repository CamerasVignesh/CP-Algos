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

const int INF = 1e6;

int solveA2(string s, vector<vector<int>> adj)
{
    int ans = INF;

    int n = s.size();

    vector<vector<int>> dist(26, vector<int>(26, INF));

    for (int i = 0; i < 26; i++)
    {
        dist[i][i] = 0;
        for (int neighbour : adj[i])
        {
            dist[i][neighbour] = 1;
        }
    }

    for (int alphabet = 0; alphabet < 26; alphabet++)
    {
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][alphabet] + dist[alphabet][j]);
            }
        }
    }

    int curr = 0;

    for (int target = 0; target < 26; target++)
    {
        curr = 0;
        for (int i = 0; i < n; i++)
        {
            int thisDist = dist[s[i] - 'A'][target];
            if (thisDist == INF)
            {
                curr = INF;
                break;
            }
            curr += thisDist;
        }
        ans = min(ans, curr);
    }

    return ans;
}

int mainFuncA2()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ifstream inputStream("input.txt");
    ofstream outStream;
    outStream.open("output.txt");
    string line = "";
    if (inputStream.is_open())
    {
        int T;
        inputStream >> T;
        for (int tt = 1; tt <= T; tt++)
        {
            vector<vector<int>> adj(26);
            string s;
            inputStream >> s;
            int k;
            inputStream >> k;
            for (int i = 0; i < k; i++)
            {
                char u, v;
                inputStream >> u >> v;
                adj[u - 'A'].push_back(v - 'A');
            }
            int ans = solveA2(s, adj);
            if (ans == INF)
            {
                ans = -1;
            }
            outStream << "Case #" << tt << ": " << ans << "\n";
        }
        inputStream.close();
        outStream.close();
    }

}