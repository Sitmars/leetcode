/*
142. Linked List Cycle II

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *);
ListNode *detectCycle2(ListNode *);

int main()
{
	ListNode* node0 = new ListNode(0);
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	node0->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node1;
	ListNode* begin = detectCycle2(node1);
	cout << begin->val << endl;

	system("pause");
	return 0;
}

ListNode *detectCycle(ListNode *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	ListNode* begin = head;
	ListNode* walker = head;
	ListNode* runner = head;
	while (runner->next && runner->next->next)
	{
		walker = walker->next;
		runner = runner->next->next;
		if (walker == runner)
		{
			while (begin != walker)
			{
				walker = walker->next;
				if (walker == runner)
				{
					begin = begin->next;
				}
			}
			return begin;
		}
	}
	return NULL;
}

ListNode *detectCycle2(ListNode *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	ListNode* begin = head;
	ListNode* walker = head;
	ListNode* runner = head;
	int steps = 0;
	while (runner->next && runner->next->next)
	{
		steps += 1;
		walker = walker->next;
		runner = runner->next->next;
		if (walker == runner)
		{
			while (begin != walker)
			{
				begin = begin->next;
				walker = walker->next;
			}
			return begin;
		}
	}
	return NULL;
}