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