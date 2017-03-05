/*
97. Interleaving String

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isInterleave(string, string, string);

int main()
{
	string s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
	string s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
	string s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
	/*string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbbaccc";*/
	bool result = isInterleave(s1, s2, s3);
	cout << result << endl;

	system("pause");
	return 0;
}

bool isInterleave(string s1, string s2, string s3)
{
	if (s3.length() != s1.length() + s2.length())
	{
		return false;
	}
	vector<vector<bool>> substr(s1.length()+1, vector<bool>(s2.length()+1, false));
	for (int i = 0; i <= s1.length(); ++i)
	{
		for (int j = 0; j <= s2.length(); ++j)
		{
			if (i == 0 && j == 0)
			{
				substr[0][0] = true;
			}
			else if (i == 0)
			{
				substr[0][j] = substr[0][j - 1] && s2[j - 1] == s3[j - 1];
			}
			else if (j == 0)
			{
				substr[i][0] = substr[i - 1][0] && s1[i - 1] == s3[i - 1];
			}
			else
			{
				substr[i][j] = (substr[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (substr[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}
	}
	return substr[s1.length()][s2.length()];
}