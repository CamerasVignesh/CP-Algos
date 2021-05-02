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


double maxProbability(int n, const vector<vector<int>>& edges, const vector<double>& succProb, const int start, const int end)
{
    vector<vector<pair<double, int>>> adj(n);
    set<pair<double, int>> members;
    vector<double> prob(n, 0);
    for (int i = 0; i < (int)edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        double cost = succProb[i];
        adj[u].emplace_back(cost, v);
        adj[v].emplace_back(cost, u);
    }

    for (int i = 0; i < n; i++)
    {
        if (i == start)
        {
            members.insert(make_pair(1.0, i));
        }
        else
        {
            members.insert(make_pair(0.0, i));
        }
    }

    prob[start] = 1.0;

    for (int i = 0; i < n; i++)
    {
        pair<double, int> biggest = *members.rbegin();
        members.erase(members.find(biggest));

        for (pair<double, int> neighbour : adj[biggest.second])
        {
            double possibleNext = biggest.first * neighbour.first;
            if (possibleNext > prob[neighbour.second])
            {
                auto it = members.find(make_pair(prob[neighbour.second], neighbour.second));
                members.erase(it);
                prob[neighbour.second] = possibleNext;
                members.insert(make_pair(possibleNext, neighbour.second));
            }
        }
    }
    return prob[end];
}


double maxProbabilityPriorityQueue(int n, const vector<vector<int>>& edges, const vector<double>& succProb, const int start, const int end)
{
    vector<vector<pair<int, double>>> adj(n);
    vector<double> prob(n, 0);
    vector<bool> visited(n, false);
    for (int i = 0; i < (int)edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        double cost = succProb[i];
        adj[u].emplace_back(v, cost);
        adj[v].emplace_back(u, cost);
    }

    priority_queue<pair<double, int>> q;
    q.push(make_pair(1.0, start));

    prob[start] = 1.0;
    while (!q.empty())
    {
        pair<double, int> biggest = q.top();
        q.pop();
        int parent = biggest.second;
        double parentProb = biggest.first;
        if (!visited[parent])
        {
            visited[parent] = true;
            for (pair<int, double> neighbour : adj[parent])
            {
                double nextPossible = parentProb * neighbour.second;
                if (prob[neighbour.first] < nextPossible)
                {
                    prob[neighbour.first] = nextPossible;
                    q.push(make_pair(nextPossible, neighbour.first));
                }

            }
        }
    }

    return prob[end];
}