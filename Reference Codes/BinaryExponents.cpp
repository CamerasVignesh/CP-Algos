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

//Calculating x^n
long long power(long long x, long long n)
{
    long long ans = 1;
    while (n > 0)
    {
        if (n % 2)
        {
            ans *= x;
        }
        x = x * x;
        n = n / 2;
    }
    return ans;
}