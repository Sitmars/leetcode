/*
167. Two Sum II - Input array is sorted

Given an array of integers that is already sorted in ascending order,
 find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target,
 where index1 must be less than index2.
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> twoSum(vector<int>&, int);

int main()
{
	int target = 9;
	vector<int> nums = { 2,7,11,15 };
	vector<int> index = twoSum(nums, target);
	cout << index[0] << " " << index[1] << endl;

	system("pause");
	return 0;
}

vector<int> twoSum(vector<int>& numbers, int target)
{
	vector<int> index;
	index.push_back(0);
	index.push_back(numbers.size() - 1);
	while (numbers[index[0]] + numbers[index[1]] != target)
	{
		if (numbers[index[0]] + numbers[index[1]] < target)
		{
			index[0] += 1;
		}
		else
		{
			index[1] -= 1;
		}
	}
	index[0] += 1;
	index[1] += 1;
	return index;
}