/*
Merge k sorted linked lists and return it as one sorted nodept.
Analyze and describe its complexity.
*/

/**
* Definition for singly-linked nodept.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists);
ListNode* merge2Lists(ListNode*, ListNode*);

int main()
{
	ListNode* nodept;
	vector<ListNode*> lists;

	ListNode l1(1);
	nodept = &l1;
	nodept->next = new ListNode(2);
	nodept = nodept->next;
	nodept->next = new ListNode(3);

	ListNode l2(4);
	nodept = &l2;
	nodept->next = new ListNode(5);
	nodept = nodept->next;
	nodept->next = new ListNode(6);
	nodept = nodept->next;
	nodept->next = new ListNode(7);

	ListNode l3(-1);
	nodept = &l3;
	nodept->next = new ListNode(8);
	nodept = nodept->next;
	nodept->next = new ListNode(11);

	ListNode l4(-2);
	nodept = &l4;
	nodept->next = new ListNode(9);
	nodept = nodept->next;
	nodept->next = new ListNode(12);

	lists.push_back(&l1);
	lists.push_back(&l2);
	lists.push_back(&l3);
	lists.push_back(&l4);

	nodept = mergeKLists(lists);

	while (nodept)
	{
		cout << nodept->val << " ";
		nodept = nodept->next;
	}
	cout << endl;

	system("pause");
	return 0;
}

ListNode* mergeKLists(vector<ListNode*>& lists)
{
	if (lists.empty())
	{
		return NULL;
	}
	int len = lists.size();
	while (len > 1)
	{
		for (int i = 0; i < len / 2; ++i)
		{
			lists[i] = merge2Lists(lists[i], lists[len - i - 1]);
		}
		if (len % 2 != 0)
		{
			len += 1;
		}
		len /= 2;
	}
	return lists.front();
}

ListNode* merge2Lists2(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	ListNode* head = new ListNode(0);
	ListNode* tail = head;
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	if (l1)
	{
		tail->next = l1;
	}
	else if (l2)
	{
		tail->next = l2;
	}
	return head->next;
}

ListNode* merge2Lists(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	if (l1->val < l2->val)
	{
		l1->next = merge2Lists(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = merge2Lists(l1, l2->next);
		return l2;
	}
}