/*
153. Find Minimum in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findMin(vector<int>&);
int findmin(vector<int>&, int, int);

int main()
{
	vector<int> nums = { 3,3,1 };
	int result = findMin(nums);
	cout << result << endl;

	system("pause");
	return 0;
}

int findMin(vector<int>& nums)
{
	int minnum = findmin(nums, 0, nums.size() - 1);
	if (minnum < nums[0])
	{
		return minnum;
	}
	return nums[0];
}

int findmin(vector<int>& nums, int start, int end)
{
	if (end - start + 1 <= 2)
	{
		return nums[end];
	}
	int mid = (end + start) / 2;
	if (nums[mid] > nums[start])
	{
		return findmin(nums, mid, end);
	}
	else
	{
		return findmin(nums, start, mid);
	}
}