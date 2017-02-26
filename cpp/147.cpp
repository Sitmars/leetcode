/*
147. Insertion Sort List

Sort a linked list using insertion sort.
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

ListNode* insertionSortList(ListNode*);

int main()
{
	ListNode* node1 = new ListNode(2);
	ListNode* node2 = new ListNode(4);
	ListNode* node3 = new ListNode(2);
	ListNode* node4 = new ListNode(5);
	ListNode* node5 = new ListNode(2);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	ListNode* head = insertionSortList(node1);
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

	system("pause");
	return 0;
}

ListNode* insertionSortList(ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode* tail = head;
	ListNode* node = head->next;
	ListNode* pos;
	while (node)
	{
		if (head->val >= node->val)
		{
			tail->next = node->next;
			node->next = head;
			head = node;
			node = tail->next;
			continue;
		}
		pos = head;
		while (pos != tail)
		{
			if (pos->next->val >= node->val)
			{
				tail->next = node->next;
				node->next = pos->next;
				pos->next = node;
				node = tail->next;
				break;
			}
			pos = pos->next;
		}
		if (pos == tail)
		{
			tail = node;
			node = tail->next;
		}
	}
	return head;
}