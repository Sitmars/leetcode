/*
143. Reorder List

Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
#include<unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode*);
void reorderList2(ListNode*);

int main()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	/*ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);*/
	node1->next = node2;
	/*node2->next = node3;
	node3->next = node4;
	node4->next = node5;*/
	reorderList2(node1);
	ListNode* node = node1;
	while (node)
	{
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;

	system("pause");
	return 0;
}

void reorderList(ListNode* head)
{
	if (head == NULL)
	{
		return;
	}
	unordered_map<int, ListNode*> ord2add;
	ListNode* node = head;
	int ord = 0;
	while (node)
	{
		ord += 1;
		ord2add[ord] = node;
		node = node->next;
	}
	for (int i = 1; i <= ord / 2; ++i)
	{
		ord2add[i]->next = ord2add[ord + 1 - i];
		ord2add[ord + 1 - i]->next = ord2add[i + 1];
	}
	ord2add[ord / 2 + 1]->next = NULL;
}

void reorderList2(ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return;
	}
	ListNode* walker = head;
	ListNode* runner = head;
	//find the middle node
	while (runner->next && runner->next->next)
	{
		walker = walker->next;
		runner = runner->next->next;
	}
	//reverse the half after middle
	ListNode* tail = walker->next;
	walker->next = NULL;
	walker = tail->next;
	tail->next = NULL;
	while (walker)
	{
		runner = walker->next;
		walker->next = tail;
		tail = walker;
		walker = runner;
	}
	//merge two half
	walker = tail;
	while (tail)
	{
		walker = walker->next;
		tail->next = head->next;
		head->next = tail;
		head = tail->next;
		tail = walker;
	}
}