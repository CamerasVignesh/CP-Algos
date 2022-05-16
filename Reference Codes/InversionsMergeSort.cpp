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
#include <random>

using namespace std;

using ll = long long;

const vector<int> dx = { 0, 1, 0, -1 };

const vector<int> dy = { 1, 0, -1, 0 };

const int MOD = 1e9 + 7;

const int INF = 1e9 + 5;

ll Merge(int left, int mid, int right, vector<int>& temp, vector<int>& a)
{
    ll inversions = 0;
    if (left < right)
    {
        for (int i = left; i < mid; i++)
        {
            int index = upper_bound(a.begin() + mid, a.begin() + right + 1, a[i]) - a.begin() - mid;
            inversions += (ll)index;
        }
        int i = left;
        int j = mid;
        int k = left;
        while (i < mid && j <= right)
        {
            if (a[i] < a[j])
            {
                temp[k] = a[i];
                i++;
            }
            else
            {
                temp[k] = a[j];
                j++;
            }
            k++;
        }
        while (i < mid)
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        while (j <= right)
        {
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    else if (left == right)
    {
        temp[left] = a[left];
    }
    for (int i = left; i <= right; i++)
    {
        a[i] = temp[i];
    }
    return inversions;
}

void print(const vector<int>& a, int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        cout << a[i] << " ";
    }
}

ll MergeSort(int left, int right, vector<int>& temp, vector<int>& a)
{
    ll invCount = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;
        ll leftInvCount = MergeSort(left, mid, temp, a);
        ll rightInvCount = MergeSort(mid + 1, right, temp, a);
        ll bothInvCount = Merge(left, mid + 1, right, temp, a);
        invCount = leftInvCount + rightInvCount + bothInvCount;
    }
    else if (left == right)
    {
        temp[left] = a[left];
    }
    /*print(a, left, right);
    cout << ": " << invCount << "\n";*/
    return invCount;
}