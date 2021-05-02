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

const int INF = 1e9 + 5;

class compareClass
{
public:
    bool operator() (pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int networkDelayTime(vector<vector<int>>& times, int n, int k)
{
    //1 indexed so doing n++
    n++;
    vector<vector<pair<int, int>>> adj(n);
    vector<int> allTimes(n, INF);
    vector<bool> visited(n, false);
    for (int i = 0; i < (int)times.size(); i++)
    {
        int u = times[i][0];
        int v = times[i][1];
        int time = times[i][2];
        adj[u].push_back(make_pair(v, time));
    }
    allTimes[k] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compareClass> q;
    q.push(make_pair(k, 0));
    while (!q.empty())
    {
        pair<int, int> smallest = q.top();
        q.pop();
        int parent = smallest.first;
        int parentTime = smallest.second;
        if (!visited[parent])
        {
            visited[parent] = true;
            for (pair<int, int> neighbour : adj[smallest.first])
            {
                int nextPossible = parentTime + neighbour.second;
                if (allTimes[neighbour.first] > nextPossible)
                {
                    allTimes[neighbour.first] = nextPossible;
                    q.push(make_pair(neighbour.first, nextPossible));
                }
            }
        }
    }

    int ans = -1;

    for (int i = 1; i <= n; i++)
    {
        if (allTimes[i] == INF)
        {
            return -1;
        }
        ans = max(ans, allTimes[i]);
    }
    return ans;

}