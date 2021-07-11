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

vector<int> primes(int n)
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
    return primeValues;
}