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


class Trie 
{
public:

    vector<vector<int>> trie;

    vector<bool> end;

    int N;

    Trie()
    {
        trie.clear();
        end.clear();
        trie.push_back(vector<int>(26));
        end.push_back(false);
        N = 0;
    }

    void insert(string word)
    {
        int node = 0;
        for (char letter : word)
        {
            if (trie[node][letter - 'a'] == 0)
            {
                trie.push_back(vector<int>(26));
                end.push_back(false);
                trie[node][letter - 'a'] = ++N;
            }
            node = trie[node][letter - 'a'];
        }
        end[node] = true;
    }

    bool search(string word)
    {
        int node = 0;
        bool stop = true;
        for (char letter : word)
        {
            if (trie[node][letter - 'a'] == 0)
            {
                stop = false;
                break;
            }
            else
            {
                node = trie[node][letter - 'a'];
            }
        }
        stop = stop && end[node];
        return stop;
    }

    bool startsWith(string prefix)
    {
        int node = 0;
        bool stop = true;
        for (char letter : prefix)
        {
            if (trie[node][letter - 'a'] == 0)
            {
                stop = false;
                break;
            }
            else
            {
                node = trie[node][letter - 'a'];
            }
        }
        return stop;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */