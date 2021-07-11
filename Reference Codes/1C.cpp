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

const int INF = 1e9 + 7;

//void solve(int tt)
//{
//    int n, k;
//    cin >> n >> k;
//    multiset<int> values;
//    for (int i = 0; i < n; i++)
//    {
//        int temp;
//        cin >> temp;
//        values.insert(temp);
//    }
//    int maxCount = 0;
//    for (int i = 1; i <= k; i++)
//    {
//        for (int j = 1; j <= k; j++)
//        {
//            int firstNumber = i;
//            int secondNumber = j;
//            int count = 0;
//            for (int c = 1; c <= k; c++)
//            {
//                auto it = values.lower_bound(c);
//                int minAlready = INF;
//                int minNow = INF;
//                if (it == values.begin())
//                {
//                    minAlready = min(minAlready, abs(*it - c));
//                }
//                else if (it == values.end())
//                {
//                    minAlready = min(minAlready, abs(*values.rbegin() - c));
//                }
//                else
//                {
//                    auto it2 = it;
//                    --it2;
//                    minAlready = min({ minAlready, abs(*it - c), abs(*it2 - c) });
//                }
//
//                minNow = min({ minNow, abs(firstNumber - c), abs(secondNumber - c)});
//
//                if (minNow < minAlready)
//                {
//                    count++;
//                }
//            }
//            if (maxCount < count)
//            {
//                maxCount = count;
//            }
//        }
//    }
//    double ans = (double)maxCount / k;
//
//    cout << "Case #" << tt << ": " << ans << "\n";
//
//}
//
//void solve(int tt)
//{
//    int n, k;
//    cin >> n >> k;
//    vector<int> values;
//    vector<int> intervalSizes;
//    for (int i = 0; i < n; i++)
//    {
//        int temp;
//        cin >> temp;
//        values.push_back(temp);
//    }
//    sort(values.begin(), values.end());
//    for (int i = 0; i < values.size() - 1; i++)
//    {
//        intervalSizes.push_back(values[i + 1] - values[i]);
//    }
//    sort(intervalSizes.begin(), intervalSizes.end(), greater<int>());
//
//    int maxDiff1 = 0;
//    int maxDiff2 = 0;
//
//    for (int i = 0; i < (int)intervalSizes.size(); i++)
//    {
//        if (intervalSizes[i] >= 4)
//        {
//            if (maxDiff1 == 0)
//            {
//                maxDiff1 = max(maxDiff1, intervalSizes[i] - 5 + 2);
//            }
//            else
//            {
//                maxDiff2 = max(maxDiff2, intervalSizes[i] - 5 + 2);
//            }
//        }
//        else
//        {
//            if (maxDiff1 == 0)
//            {
//                maxDiff1 = 1;
//            }
//            else
//            {
//                maxDiff2 = 1;
//            }
//        }
//    }
//
//    int leftMax = 0;
//    int rightMax = 0;
//    if (values[0] != 1)
//    {
//        leftMax = values[0] - 1;
//    }
//    if (values[values.size() - 1] != k)
//    {
//        rightMax = k - values[values.size() - 1];
//    }
//    
//    vector<int> numbers = { leftMax, rightMax, maxDiff1, maxDiff2 };
//    sort(numbers.begin(), numbers.end(), greater<int>());
//
//    double ans = (double)numbers[0] + (double)numbers[1];
//    ans = ans / (double)k;
//    cout << "Case #" << tt << ": " << ans << "\n";
//
//}

//class compareString
//{
//public:
//    bool operator() (const string& a, const string& b)
//    {
//        return (int)a.size() <= (int)b.size();
//    }
//};
//
//
//void solve(int tt)
//{   
//    priority_queue<string, vector<string>, compareString> nextPossibles;
//    string s;
//    cin >> s;    
//    for (int digits = 1; digits <= s.size() / 2; digits++)
//    {
//        string start = s.substr(0, digits);
//        long long val = stoll(start);
//
//        long long copy = val;
//        long long end = 1;
//        while (copy > 0)
//        {
//            copy = copy / 10;
//            end = 10 * end;
//        }
//        for (long long i = val; i <= end; i++)
//        {
//            long long temp = i;
//            string ans = to_string(i);
//            while (ans.size() < (int)s.size())
//            {
//                temp++;
//                ans += to_string(temp);
//            }
//            nextPossibles.push(ans);
//        }
//    }
//
//    while(!nextPossibles.empty())
//    {
//        string curr = nextPossibles.top();
//        if (curr == s)
//        {
//            nextPossibles.pop();
//        }
//        if ((int)curr.size() < (int)s.size())
//        {
//            nextPossibles.pop();
//        }
//        if ((int)curr.size() > (int)s.size())
//        {
//            cout << "Case #" << tt << ": " << curr << "\n";
//            return;
//        }
//        bool greaterthan = true;        
//        for (int i = 0; i < (int)s.size(); i++)
//        {
//            if (curr[i] <= s[i])
//            {
//                greaterthan = false;
//                break;
//            }
//        }
//        if (!greaterthan)
//        {
//            cout << "Case #" << tt << ": " << curr << "\n";
//            return;
//        }
//    }
//
//    cout << nextPossibles.top() << "\n";
//}
//
//string getTruncatedString(string s)
//{
//    string cmp = "";
//    int i = 0;
//    while (i < (int)s.size() && s[i] == '0')
//    {
//        i++;
//    }
//    if (i < (int)s.size())
//    {
//        cmp = s.substr(i, (int)s.size() - i + 1);
//    } 
//
//    if (cmp == "")
//    {
//        cmp = "0";
//    }
//
//    return cmp;
//}
//
//bool compare(string now, string e)
//{
//    string cmp = getTruncatedString(now);
//    if (cmp == e)
//    {
//        return true;
//    }
//    return false;
//}
//
//
//string notString(string s)
//{
//    string ans = "";
//    for (int i = 0; i < (int)s.size(); i++)
//    {
//        if (s[i] == '0')
//        {
//            ans += '1';
//        }
//        else
//        {
//            ans += '0';
//        }
//    }
//    ans = getTruncatedString(ans);
//    if (ans == "")
//    {
//        ans = "0";
//    }
//    return ans;
//}

//void solve(int tt)
//{
//    string s;
//    string e;
//    cin >> s >> e;
//    cout << "Case #" << tt << ": ";
//    if (compare(s,e))
//    {
//        cout << 0 << "\n";
//        return;
//    }
//    int maxlayers = 10;
//    int layers = 0;
//    queue<string> q;
//    q.push(s);
//    set<string> already;
//    already.insert(s);
//    while (layers <= maxlayers && !q.empty())
//    {
//        layers++;
//        int count = q.size();
//        while (count--)
//        {
//            string node = q.front();
//            q.pop();            
//            string op1 = node + '0';
//            if (already.find(getTruncatedString(op1)) == already.end() && already.find(op1) == already.end())
//            {
//                q.push(op1);
//                already.insert(op1);
//                if (compare(op1, e))
//                {
//                    cout << layers << "\n";
//                    return;
//                }
//            }
//            string op2 = notString(node);
//            if (already.find(getTruncatedString(op2)) == already.end() && already.find(op2) == already.end())
//            {
//                q.push(op2);
//                already.insert(op2);
//                if (compare(op2, e))
//                {
//                    cout << layers << "\n";
//                    return;
//                }
//            }
//        }
//    }
//    cout << "IMPOSSIBLE" << "\n";
//}