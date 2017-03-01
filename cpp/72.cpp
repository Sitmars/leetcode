/*
72. Edit Distance

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2.
(each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

	a) Insert a character
	b) Delete a character
	c) Replace a character

"mart" "karma"
"pneumonoultramicroscopicsilicovolcanoconiosis" "stereomicroscopically"
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int minDistance(string, string);

int main()
{
	string word1 = "a";
	string word2 = "p";
	int mindis = minDistance(word1, word2);
	cout << mindis << endl;

	system("pause");
	return 0;
}

int minDistance(string word1, string word2)
{
	vector<vector<int>> steps(word1.length()+1, vector<int>(word2.length()+1, 0));
	for (int i = 1; i <= word1.length(); ++i)
	{
		steps[i][0] = i;
	}
	for (int j = 0; j <= word2.length(); ++j)
	{
		steps[0][j] = j;
	}
	for (int i = 1; i <= word1.length(); ++i)
	{
		for (int j = 1; j <= word2.length(); ++j)
		{
			if (word1[i - 1] == word2[j - 1])
			{
				steps[i][j] = steps[i - 1][j - 1];
			}
			else
			{
				int minstep = steps[i - 1][j - 1] < steps[i - 1][j] ? steps[i - 1][j - 1] : steps[i - 1][j];
				minstep = minstep < steps[i][j - 1] ? minstep : steps[i][j - 1];
				steps[i][j] = minstep + 1;
			}
		}
	}
	return steps.back().back();
}