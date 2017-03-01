/*
87. Scramble String

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

		great
	   /    \
	  gr    eat
	 / \    /  \
	g   r  e   at
			   / \
			  a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

		rgeat
	   /    \
	  rg    eat
	 / \    /  \
	r   g  e   at
			   / \
			  a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

		rgtae
	   /    \
	  rg    tae
	 / \    /  \
	r   g  ta  e
		  / \
		 t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/
////
//1.Ψһ�����������Ͻ磨��ʼΪ0�����½磨��ʼΪn-1��
//2.��s���ַ��ظ�ʱ������s2�����в�Ψһ�����жϵ������ַ���ʱ�򣬱����������Դ�����
//3.��set�е���λΪ�½磬���ҳ���Ϊĩλ����λʱ����set��ĩλΪ�Ͻ磬�ҳ���Ϊĩλ����λʱ��set�й���ǰ��/�����������
//  set������ֵ�½�/�Ͻ�
//4.��set��ͬʱ����0��n-1ʱ������false

#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>

using namespace std;

bool isScramble(string, string);

int main()
{
	string s1 = "book";
	string s2 = "okbo";
	bool result = isScramble(s1, s2);
	cout << result << endl;

	system("pause");
	return 0;
}

bool isScramble(string s1, string s2)
{
	if (s1 == s2)
	{
		return true;
	}
	vector<int> chars(26, 0);
	for (int i = 0; i < s1.length(); ++i)
	{
		chars[s1[i] - 'a'] += 1;
		chars[s2[i] - 'a'] -= 1;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (chars[i] != 0)
		{
			return false;
		}
	}
	for (int i = 1; i < s1.length(); ++i)
	{
		if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
		{
			return true;
		}
		if (isScramble(s1.substr(0, i), s2.substr(s1.length() - i)) && isScramble(s1.substr(i), s2.substr(0, s1.length() - i)))
		{
			return true;
		}
	}
	return false;
}