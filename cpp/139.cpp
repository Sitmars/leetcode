/*
139. Word Break

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
determine if s can be segmented into a space-separated sequence of one or more dictionary words.
You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings).
Please reload the code definition to get the latest changes.
*/

#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

bool wordBreak(string, vector<string>&);
bool wordBreak2(string, vector<string>&);
bool wordBreak3(string, vector<string>&);

int main()
{
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	vector<string> wordDict = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	int result = wordBreak3(s, wordDict);
	cout << result << endl;

	system("pause");
	return 0;
}

bool wordBreak(string s, vector<string>& wordDict)
{
	set<string> dict;
	for (int i = 0; i < wordDict.size(); ++i)
	{
		dict.insert(wordDict[i]);
	}
	vector<int> next;
	next.push_back(0);
	string word;
	int head;
	int tail = 0;
	while (!next.empty())
	{
		head = next.back();
		while (tail < s.length())
		{
			word = s.substr(head, tail - head +1);
			if (dict.find(word) != dict.end())
			{
				if (tail + 1 == s.length())
				{
					return true;
				}
				next.push_back(tail + 1);
				break;
			}
			tail += 1;
		}
		if (tail == s.length())
		{
			tail = next.back();
			next.pop_back();
		}
		else
		{
			tail = next.back();
		}
	}
	return false;
}

bool wordBreak2(string s, vector<string>& wordDict)
{
	vector<bool> broken(s.length() + 1, false);
	broken[0] = 1;
	set<string> dict;
	for (int i = 0; i < wordDict.size(); ++i)
	{
		dict.insert(wordDict[i]);
	}
	for (int i = 1; i <= s.length(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (broken[j] && dict.find(s.substr(j, i-j)) != dict.end())
			{
				broken[i] = true;
			}
		}
	}
	return broken.back();
}

bool wordBreak3(string s, vector<string>& wordDict)
{
	vector<bool> broken(s.length() + 1, false);
	broken[0] = 1;
	set<string> dict;
	for (int i = 0; i < wordDict.size(); ++i)
	{
		dict.insert(wordDict[i]);
	}
	for (int i = 1; i <= s.length(); ++i)
	{
		for (int j = i-1; j >= 0; --j)
		{
			if (broken[j])
			{
				if (dict.find(s.substr(j, i - j)) != dict.end())
				{
					broken[i] = true;
					break;
				}
			}
		}
	}
	return broken.back();
}