/*
141. Linked List Cycle

Given a linked list, determine if it has a cycle in it.

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

bool hasCycle(ListNode *);

int main()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	node1->next = node2;
	node2->next = node3;
	node3->next = node1;
	bool result = hasCycle(node1);
	cout << result << endl;

	system("pause");
	return 0;
}

bool hasCycle(ListNode *head)
{
	if (head == NULL)
	{
		return false;
	}
	ListNode* walker = head;
	ListNode* runner = head;
	while (runner->next && runner->next->next)
	{
		walker = walker->next;
		runner = runner->next->next;
		if (walker == runner)
		{
			return true;
		}
	}
	return false;
}