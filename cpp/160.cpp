/*
160. Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 ¡ú a2
					¨K
					c1 ¡ú c2 ¡ú c3 ¡ú null
					¨J
B:     b1 ¡ú b2 ¡ú b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
#include<time.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode*, ListNode*);

int main()
{
	srand(time(0));
	ListNode* a1 = new ListNode(rand() % 10);
	ListNode* a2 = new ListNode(rand() % 10);
	ListNode* b1 = new ListNode(rand() % 10);
	ListNode* b2 = new ListNode(rand() % 10);
	ListNode* b3 = new ListNode(rand() % 10);
	ListNode* c1 = new ListNode(rand() % 10);
	ListNode* c2 = new ListNode(rand() % 10);
	ListNode* c3 = new ListNode(rand() % 10);
	a1->next = a2;
	a2->next = c1;
	b1->next = b2;
	b2->next = b3;
	b3->next = c1;
	c1->next = c2;
	c2->next = c3;
	ListNode* node = getIntersectionNode(a1, b1);
	cout << "hehe" << endl;

	system("pause");
	return 0;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	if (headA == NULL || headB == NULL)
	{
		return NULL;
	}
	ListNode* nodeA = headA;
	ListNode* nodeB = headB;
	while (nodeA && nodeB && nodeA != nodeB)
	{
		nodeA = nodeA->next;
		nodeB = nodeB->next;
		if (nodeA == nodeB)
		{
			return nodeA;
		}
		if (nodeA == NULL)
		{
			nodeA = headB;
		}
		if (nodeB == NULL)
		{
			nodeB = headA;
		}
	}
	return nodeA;
}