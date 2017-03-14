/*
168. Excel Sheet Column Title

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

	1 -> A
	2 -> B
	3 -> C
	...
	26 -> Z
	27 -> AA
	28 -> AB
*/

#include<iostream>
#include<string>

using namespace std;

string convertToTitle(int);

int main()
{
	int num = 2147483647;
	string title = convertToTitle(num);
	cout << title << endl;

	int base = 1;
	num = 0;
	for (int i = 0; i < title.length(); ++i)
	{
		num += (title[title.length() - i - 1] - 'A' + 1)*base;
		base *= 26;
	}
	cout << num << endl;

	system("pause");
	return 0;
}

string convertToTitle(int n)
{
	string title = "";
	int bit;
	while (n != 0)
	{
		bit = n % 26;
		if (bit == 0)
		{
			title += 'Z';
			n -= 26;
		}
		else
		{
			title += 'A' - 1 + bit;
		}
		n /= 26;
	}
	reverse(title.begin(), title.end());
	return title;
}