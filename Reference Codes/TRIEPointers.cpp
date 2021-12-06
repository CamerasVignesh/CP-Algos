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

/*Given an array of strings words representing an English Dictionary, 
return the longest word in words that can be built one character at a time by other words in words.

If there is more than one possible answer, return the longest word with the smallest lexicographical order. 
If there is no answer, return the empty string.

Input: words = ["a","banana","app","appl","ap","apply","apple"]
Output: "apple"
Explanation: Both "apply" and "apple" can be built from other words in the dictionary. 
However, "apple" is lexicographically smaller than "apply".
*/



class Solution
{
public:

	class TrieNode
	{
	public:
		bool word;
		vector<TrieNode*> children;

		TrieNode()
		{
			word = false;
			for (int i = 0; i < 26; i++)
			{
				children.push_back(NULL);
			}
		}

	};

	class Trie
	{
		TrieNode* root;

	public:

		Trie()
		{
			root = new TrieNode();
		}

		void Build(const vector<string>& words)
		{
			for (string word : words)
			{
				TrieNode* node = root;
				for (char letter : word)
				{
					if (node->children[letter - 'a'] == NULL)
					{
						TrieNode* newNode = new TrieNode();
						node->children[letter - 'a'] = newNode;
					}
					node = node->children[letter - 'a'];
				}
				node->word = true;
			}
		}

		void dfs(TrieNode* node, string curr, string& ans)
		{
			if (node == NULL)
			{
				return;
			}

			if (node->word && ans.size() < curr.size())
			{
				ans = curr;
			}

			for (int c = 0; c < 26; c++)
			{
				if (node->children[c] != NULL && node->children[c]->word)
				{
					dfs(node->children[c], curr + char(c + 'a'), ans);
				}
			}

		}

		string FindLongestWord()
		{
			string ans = "";
			dfs(root, "", ans);
			return ans;
		}

	};

	string longestWord(vector<string>& words)
	{
		Trie* trie = new Trie();
		auto compare = [&](const string& word1, const string& word2)
		{
			return word1.size() < word2.size();
		};
		sort(words.begin(), words.end(), compare);
		trie->Build(words);
		string ans = trie->FindLongestWord();
		return ans;
	}
};

