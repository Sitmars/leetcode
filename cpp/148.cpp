/*
148. Sort List

Sort a linked list in O(n log n) time using constant space complexity.
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

ListNode* sortList(ListNode*);

int main()
{
	ListNode* node1 = new ListNode(5);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(1);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	ListNode* head = sortList(node1);
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

	system("pause");
	return 0;
}

ListNode* sortList(ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode* walker = head;
	ListNode* runner = head;
	while (runner->next && runner->next->next)
	{
		walker = walker->next;
		runner = runner->next->next;
	}
	if (walker == runner)
	{
		if (walker->val > walker->next->val)
		{
			runner = runner->next;
			runner->next = walker;
			walker->next = NULL;
			return runner;
		}
		return head;
	}
	else
	{
		runner = walker->next;
		walker->next = NULL;
		walker = sortList(head);
		runner = sortList(runner);
		if (walker->val < runner->val)
		{
			head = walker;
			walker = walker->next;
		}
		else
		{
			head = runner;
			runner = runner->next;
		}
		ListNode* tail = head;
		while (walker && runner)
		{
			if (walker->val < runner->val)
			{
				tail->next = walker;
				tail = tail->next;
				walker = walker->next;
			}
			else
			{
				tail->next = runner;
				tail = tail->next;
				runner = runner->next;
			}
		}
		if (walker)
		{
			tail->next = walker;
		}
		else if (runner)
		{
			tail->next = runner;
		}
		return head;
	}
}