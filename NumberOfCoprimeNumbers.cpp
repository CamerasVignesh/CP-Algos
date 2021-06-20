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


const int mxN = 1e5 + 5;

vector<int> phi(mxN);

void numberOfCoprimeNumbers()
{
    for (int i = 2; i < mxN; i++)
    {
        phi[i] = i;
    }

    for (int i = 2; i < mxN; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j < mxN; j += i)
            {
                phi[j] = phi[j] - phi[j] / i;
            }
        }
    }
}