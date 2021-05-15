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

//class compareClass
//{
//public:
//    bool operator() (pair<long long, pair<int, int>> a, pair<long long, pair<int, int>> b)
//    {
//        return a.first > b.first;
//    }
//};
//
//void solve(int tt)
//{
//    int n, m;
//    long long w;
//    const long long INF = 1e12;
//    cin >> n >> m >> w;
//    vector<vector<int>> grid(n, vector<int>(m, -1));
//    map<pair<int, int>, vector<pair<pair<int, int>, long long>>> adj;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            cin >> grid[i][j];
//        }
//    }
//
//    vector<pair<int, int>> dirs = { make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1) };
//
//    for (int row = 0; row < n; row++)
//    {
//        for (int col = 0; col < m; col++)
//        {
//            for (pair<int, int> dir : dirs)
//            {
//                int newRow = row + dir.first;
//                int newCol = col + dir.second;
//                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
//                {
//                    if (grid[row][col] == -1 || grid[newRow][newCol] == -1)
//                    {
//                        adj[make_pair(row, col)].push_back(make_pair(make_pair(newRow, newCol), INF));
//                    }
//                    else
//                    {
//                        if (grid[row][col] != 0 && grid[newRow][newCol] != 0)
//                        {
//                            adj[make_pair(row, col)].push_back(make_pair(make_pair(newRow, newCol), min(w, (long long)grid[point.first][point.second] + grid[neighbour.first][neighbour.second]))));
//                        }
//                        else
//                        {
//                            adj[make_pair(row, col)].push_back(make_pair(make_pair(newRow, newCol), w));
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    vector<pair<int, int>> portals;
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            if (grid[i][j] != 0 && grid[i][j] != -1)
//            {
//                portals.push_back(make_pair(i, j));
//            }
//        }
//    }
//
//    for (pair<int, int> point : portals)
//    {
//        for (pair<int, int> neighbour : portals)
//        {
//            if (point == neighbour)
//            {
//                continue;
//            }
//            vector<pair<pair<int, int>, long long>> neighbours = adj[point];
//            bool found = false;
//            for (int j = 0; j < (int)neighbours.size(); j++)
//            {
//                if (neighbours[j].first == neighbour)
//                {
//                    found = true;
//                    neighbours[j].second = min(neighbours[j].second, (long long)grid[point.first][point.second] + grid[neighbour.first][neighbour.second]);
//                    break;
//                }
//            }
//            if (!found)
//            {
//                neighbours.push_back(make_pair(neighbour, (long long)grid[point.first][point.second] + grid[neighbour.first][neighbour.second]));
//            }
//            adj[point] = neighbours;
//        }
//    }
//
//    map<pair<int, int>, bool> visited;
//    map<pair<int, int>, long long> dist;
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            visited[make_pair(i, j)] = false;
//            dist[make_pair(i, j)] = INF;
//        }
//    }
//
//    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, compareClass> q;
//    dist[make_pair(0, 0)] = 0;
//    q.push(make_pair(0, make_pair(0, 0)));
//
//    while (!q.empty())
//    {
//        pair<long long, pair<int, int>> node = q.top();
//        q.pop();
//        pair<int, int> parent = node.second;
//        long long cost = node.first;
//        if (!visited[parent])
//        {
//            visited[parent] = true;
//            for (pair<pair<int, int>, long long> entry : adj[parent])
//            {
//                pair<int, int> neighbour = entry.first;
//                long long neighbourCost = entry.second;
//                long long nextPossible = dist[parent] + neighbourCost;
//                if (dist[neighbour] > nextPossible)
//                {
//                    if (!visited[neighbour])
//                    {
//                        dist[neighbour] = nextPossible;
//                        q.push(make_pair(nextPossible, neighbour));
//                    }                    
//                }
//            }
//        }
//    }
//
//    if (dist[make_pair(n - 1, m - 1)] == INF)
//    {
//        cout << -1 << "\n";
//    }
//    else
//    {
//        cout << dist[make_pair(n - 1, m - 1)] << "\n";
//    }
//}

//class compareClassNew
//{
//public:
//    bool operator() (pair<int, long long> a, pair<int, long long> b)
//    {
//        return a.second > b.second;
//    }
//};
//
//void solve(int tt)
//{
//    int n, m;
//    long long w;
//    const long long INF = 1e12;
//    cin >> n >> m >> w;
//    vector<vector<int>> grid(n, vector<int>(m, -1));
//    map<pair<int, int>, int> pointMapping;
//    vector<pair<int, int>> pointVectors;
//    map<int, set<int>> currentNeighbours;
//    int pointCount = 0;    
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            cin >> grid[i][j];
//            pointVectors.push_back(make_pair(i, j));
//            pointMapping[make_pair(i, j)] = pointCount;
//            pointCount++;
//        }
//    }
//
//    vector<vector<pair<int, long long>>> adj(pointCount);
//    vector<bool> visited(pointCount, false);
//    vector<long long> dist(pointCount, INF);
//
//    vector<int> dx = { 1,0,-1,0 };
//    vector<int> dy = { 0,1,0,-1 };
//
//    for (int i = 0; i < pointCount; i++)
//    {
//        pair<int, int> point = pointVectors[i];
//        if (grid[point.first][point.second] == -1)
//        {
//            continue;
//        }
//        for (int j = 0; j < dx.size(); j++)
//        {
//            int newRow = point.first + dx[j];
//            int newCol = point.second + dy[j];
//            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
//            {
//                int neighbour = pointMapping[make_pair(newRow, newCol)];
//                if (grid[newRow][newCol] == -1)
//                {
//                    //adj[i].push_back(make_pair(neighbour, INF));
//                }
//                else 
//                {
//                    if (grid[point.first][point.second] != 0 && grid[newRow][newCol] != 0)
//                    {
//                        adj[i].push_back(make_pair(neighbour, min(w, (long long)grid[point.first][point.second] + grid[newRow][newCol])));
//                    }
//                    else
//                    {
//                        adj[i].push_back(make_pair(neighbour, w));
//                    }
//                    currentNeighbours[i].insert(neighbour);
//                }
//            }
//        }
//    }
//
//    vector<int> portals;
//    for (int row = 0; row < n; row++)
//    {
//        for (int col = 0; col < m; col++)
//        {
//            if (grid[row][col] != 0 && grid[row][col] != -1)
//            {
//                portals.push_back(pointMapping[make_pair(row, col)]);
//            }
//        }
//    }
//
//    for (int portal : portals)
//    {
//        for (int otherPortal : portals)
//        {
//            if (portal == otherPortal || currentNeighbours[portal].find(otherPortal) != currentNeighbours[portal].end())
//            {
//                continue;
//            }            
//            pair<int, int> point1 = pointVectors[portal];
//            pair<int, int> point2 = pointVectors[otherPortal];
//            adj[portal].push_back(make_pair(otherPortal, (long long)grid[point1.first][point1.second] + grid[point2.first][point2.second]));
//        }
//    }
//
//
//    priority_queue<pair<int, long long>, vector<pair<int, long long>>, compareClassNew> q;
//
//    dist[0] = 0;
//    q.push(make_pair(0, 0));
//
//    while (!q.empty())
//    {
//        pair<int, long long> parent = q.top();
//        q.pop();
//        if (!visited[parent.first])
//        {
//            visited[parent.first] = true;
//            for (pair<int, long long> child : adj[parent.first])
//            {
//                long long nextPossible = dist[parent.first] + child.second;
//                if (dist[child.first] > nextPossible)
//                {
//                    dist[child.first] = nextPossible;
//                    q.push(make_pair(child.first, nextPossible));
//                }
//            }
//        }
//    }
//
//    long long ans = -1;
//    if (dist[dist.size() - 1] != INF)
//    {
//        ans = dist[dist.size() - 1];
//    }
//    cout << ans << "\n";
//
//}

//void solve(int tt, int n, int t)
//{
//    int k;
//    cin >> k;
//    int start = 0;
//    int end = n - 1;
//    while (start < end)
//    {
//        int mid = (start + end) / 2;
//        cout << "? " << start << " " << end<<"\n"<<flush;
//        int val;
//        cin >> val;
//        int numberOfOnes = val;
//        int numberOfZeros = end - start + 1 - val;
//        if (numberOfZeros > k)
//        {
//            end = mid - 1;
//        }
//        else if (numberOfZeros < k)
//        {
//            start = mid + 1;
//            k -= numberOfZeros;
//        }
//        else
//        {
//
//        }
//    }
//}

void solve(int tt)
{

}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    //cin >> t; 
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }       
}