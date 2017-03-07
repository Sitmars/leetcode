/*
155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
	MinStack minStack = new MinStack();
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	minStack.getMin();   --> Returns -3.
	minStack.pop();
	minStack.top();      --> Returns 0.
	minStack.getMin();   --> Returns -2.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class MinStack
{
public:
	MinStack()
	{
		nums = (int*)calloc(10, sizeof(int));
		capacity = 10;
		size = -1;
		ifpop = false;
		minnum = INT_MAX;
	}
	void push(int x)
	{
		if (size + 1 == capacity)
		{
			capacity *= 2;
			int *p = (int*)calloc(capacity, sizeof(int));
			for (int i = 0; i < capacity; ++i)
			{
				p[i] = nums[i];
			}
			delete[] nums;
			nums = p;
		}
		if (!ifpop)
		{
			minnum = min(minnum, x);
		}
		++size;
		nums[size] = x;
	}
	void pop()
	{
		--size;
		ifpop = true;
	}
	int top()
	{
		return nums[size];
	}
	int getMin()
	{
		if (!ifpop)
		{
			return minnum;
		}
		minnum = INT_MAX;
		for (int i = 0; i <= size; ++i)
		{
			minnum = min(minnum, nums[i]);
		}
		ifpop = false;
		return minnum;
	}
protected:
	int size;
	int capacity;
	int *nums;
	bool ifpop;
	int minnum;
};

int main()
{
	MinStack *minstack = new MinStack();
	minstack->push(-2);
	minstack->push(0);
	minstack->push(-3);
	cout << minstack->getMin() << endl;
	minstack->pop();
	cout << minstack->top() << endl;
	cout << minstack->getMin() << endl;

	system("pause");
	return 0;
}