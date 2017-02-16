/*
137. Single Number II

Given an array of integers, every element appears three times except for one, which appears exactly once.
Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include<iostream>
#include<vector>

using namespace std;

int singleNumber(vector<int>&);

int main()
{
	vector<int> nums = { 1,0,0,0,1,1,2 };
	int result = singleNumber(nums);
	cout << result << endl;

	system("pause");
	return 0;
}

int singleNumber(vector<int>& nums)
{
	int num = 0;
	vector<int> bits(32, 0);
	for (int i = 0; i < 32; ++i)
	{
		for (int j = 0; j < nums.size(); ++j)
		{
			bits[i] += nums[j] & 1;
			nums[j] = nums[j] >> 1;
		}
		bits[i] %= 3;
		bits[i] = bits[i] << i;
		num |= bits[i];
	}
	return num;
}