/*
138. Copy List with Random Pointer

A linked list is given such that each node contains an additional random pointer \
which could point to any node in the list or null.

Return a deep copy of the list.
*/
/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/

#include<iostream>
#include<map>
#include<queue>

using namespace std;

struct RandomListNode
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

enum ptype
{
	NEXT = 0,
	RANDOM
};

RandomListNode *copyRandomList(RandomListNode*);

int main()
{
	/*RandomListNode *node1 = new RandomListNode(1);
	RandomListNode *node2 = new RandomListNode(2);
	RandomListNode *node3 = new RandomListNode(3);
	RandomListNode *node4 = new RandomListNode(4);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node1->random = node3;
	node2->random = node2;
	node3->random = node1;*/

	RandomListNode *node1 = new RandomListNode(1);
	node1->random = node1;

	RandomListNode *copy = copyRandomList(node1);
	cout << "hehe" << endl;

	system("pause");
	return 0;
}

RandomListNode *copyRandomList(RandomListNode *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	RandomListNode* newhead = NULL;
	map<RandomListNode*, RandomListNode*> old2new;
	queue<RandomListNode*> pointer;
	queue<RandomListNode*> owner;
	pointer.push(head);
	owner.push(NULL);
	int type = NEXT;
	RandomListNode* node;
	while (!pointer.empty())
	{
		if (pointer.front() == NULL)
		{
			pointer.pop();
			owner.pop();
			type = !type;
			continue;
		}
		else if (old2new.find(pointer.front()) != old2new.end())
		{
			node = old2new.find(pointer.front())->second;
		}
		else
		{
			node = new RandomListNode(pointer.front()->label);
			old2new.insert(pair<RandomListNode*, RandomListNode*>(pointer.front(), node));
			pointer.push(pointer.front()->next);
			pointer.push(pointer.front()->random);
			owner.push(pointer.front());
			owner.push(pointer.front());
		}
		if (owner.front())
		{
			if (type == NEXT)
			{
				old2new.find(owner.front())->second->next = node;
			}
			else
			{
				old2new.find(owner.front())->second->random = node;
			}
			type = !type;
		}
		else
		{
			newhead = node;
		}
		pointer.pop();
		owner.pop();
	}
	return newhead;
}