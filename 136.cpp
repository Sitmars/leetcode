/*
136. Single Number

Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity.
Could you implement it without using extra memory?

Subscribe to see which companies asked this question.
*/

#include<iostream>
#include<vector>

using namespace std;

int singleNumber(vector<int>&);

int main()
{
	vector<int> nums = { 5,2,3,4,6,5,4,3,2 };
	int result = singleNumber(nums);
	cout << result << endl;

	system("pause");
	return 0;
}

int singleNumber(vector<int>& nums)
{
	int result = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		result ^= nums[i];
	}
	return result;
}