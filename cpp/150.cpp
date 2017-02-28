/*
150. Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/


#include<iostream>
#include<vector>
#include<string>

using namespace std;

int evalRPN(vector<string>& tokens);

int main()
{
	vector<string> tokens = { "3", "-4", "+"};
	int result = evalRPN(tokens);
	cout << result << endl;

	system("pause");
	return 0;
}

int evalRPN(vector<string>& tokens)
{
	int result = 0;
	vector<int> nums;
	for (int i = 0; i < tokens.size(); ++i)
	{
		if (tokens[i][0] >= '0' && tokens[i][0] <= '9' || tokens[i][0] == '-' && tokens[i].length() != 1)
		{
			nums.push_back(atoi(tokens[i].c_str()));
		}
		else
		{
			int rightnum = nums.back();
			nums.pop_back();
			int leftnum = nums.back();
			nums.pop_back();
			switch (tokens[i][0])
			{
			case '+':
				nums.push_back(leftnum + rightnum);
				break;
			case '-':
				nums.push_back(leftnum - rightnum);
				break;
			case '*':
				nums.push_back(leftnum * rightnum);
				break;
			case '/':
				nums.push_back(leftnum / rightnum);
				break;
			default:
				break;
			}
		}
	}
	return nums[0];
}