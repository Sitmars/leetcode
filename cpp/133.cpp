/*
133. Clone Graph

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
*/
/**
* Definition for undirected graph.
* struct UndirectedGraphNode {
*     int label;
*     vector<UndirectedGraphNode *> neighbors;
*     UndirectedGraphNode(int x) : label(x) {};
* };
*/

#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *);

int main()
{
	UndirectedGraphNode* node0 = new UndirectedGraphNode(-3);
	UndirectedGraphNode* node1 = new UndirectedGraphNode(-1);
	UndirectedGraphNode* node2 = new UndirectedGraphNode(2);
	UndirectedGraphNode* node3 = new UndirectedGraphNode(3);
	UndirectedGraphNode* node4 = new UndirectedGraphNode(5);
	node0->neighbors = { node1, node3, node4 };
	node1->neighbors = { node2, node3, node3 };
	node2->neighbors = { node3 };
	node3->neighbors = { node4 };
	node4->neighbors = { node4 };
	UndirectedGraphNode* result = cloneGraph(node0);
	cout << "hehe" << endl;

	system("pause");
	return 0;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
	if (node == NULL)
	{
		return NULL;
	}
	UndirectedGraphNode* newhead = NULL;
	queue<UndirectedGraphNode*> next;
	queue<UndirectedGraphNode*> owner;
	next.push(node);
	owner.push(NULL);
	map<UndirectedGraphNode*, UndirectedGraphNode*> origin2new;
	UndirectedGraphNode* newnode;
	while (!next.empty())
	{
		if (origin2new.find(next.front()) != origin2new.end())
		{
			newnode = origin2new.find(next.front())->second;
		}
		else
		{
			newnode = new UndirectedGraphNode(next.front()->label);
			origin2new.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(next.front(), newnode));
			for (int i = 0; i < next.front()->neighbors.size(); ++i)
			{
				if (origin2new.find(next.front()->neighbors[i]) != origin2new.end())
				{
					UndirectedGraphNode* neighbor = origin2new.find(next.front()->neighbors[i])->second;
					newnode->neighbors.push_back(NULL);
					int j = newnode->neighbors.size() - 2;
					for (; j >= 0; --j)
					{
						if (newnode->neighbors[j]->label > neighbor->label)
						{
							newnode->neighbors[j + 1] = newnode->neighbors[j];
							continue;
						}
						break;
					}
					//j = j > 0 ? j : -1;
					newnode->neighbors[j + 1] = neighbor;
				}
				else
				{
					next.push(next.front()->neighbors[i]);
					owner.push(newnode);
				}
			}
		}
		if (owner.front() == NULL)
		{
			newhead = newnode;
		}
		else
		{
			owner.front()->neighbors.push_back(NULL);
			int i = owner.front()->neighbors.size() - 2;
			for (; i >= 0; --i)
			{
				if (owner.front()->neighbors[i]->label > newnode->label)
				{
					owner.front()->neighbors[i + 1] = owner.front()->neighbors[i];
					continue;
				}
				break;
			}
			//i = i > 0 ? i : -1;
			owner.front()->neighbors[i + 1] = newnode;
		}
		next.pop();
		owner.pop();
	}
	return newhead;
}