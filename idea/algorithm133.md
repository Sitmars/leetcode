##  133.   Clone Graph

**题目 :**

Clone an undirected graph. Each node in the graph contains a `label` and a list of its `neighbors`.

```
Definition for undirected graph.
 struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };
```



**题意 :**

复制一个无向图。每一个节点由一个标签（label）和一个邻接链表组成（neighbors）。节点具体结构由上面给出。

**思路 :**

（1）可以使用最好想的广度优先遍历：用两个队列保存尚未访问的邻接关系（一个存父节点，一个存子节点）。从起始节点开始，每遍历到一个邻接关系就创建子节点，并在父节点的邻接表里添加该子节点，当然若子节点已经创建就可以省却创建步骤。然后将子节点作为父节点、子节点的邻接表作为子节点存入队列。直至队列为空退出。

有一个问题需要指出：**邻接表必须按照由小到大的顺序排列**。 

（想不明白为什么，反正是邻接表，顺序没有意义啊有木有）

这是我遇到的第7/12个用例的错误：

```
Output:
{-47,-43,96#-43,-42#-42,-41#-41,-40,12#-40,-31,44,60#-31,-31,-29#-29,-27#-27,-26#-26,-24#-24,60,-20#-20,-17#-17,-15#-15,-14#-14,-10#-10,51,-8#-8,-7#-7,-1#-1,3#3,29,8#8,12#12,15#15,17#17,28#28,29#29,35#35,37#37,40#40,57,41#41,42#42,44#44,45#45,47,53#47,49#49,51#51,53#53,57#57,59,68#59,60#60,62#62,66#66,68#68,72#72,77#77,78#78,79#79,80#80,90#90,94#94,96#96}
Expected:
{-47,-43,96#-43,-42#-42,-41#-41,-40,12#-40,-31,44,60#-31,-31,-29#-29,-27#-27,-26#-26,-24#-24,-20,60#-20,-17#-17,-15#-15,-14#-14,-10#-10,-8,51#-8,-7#-7,-1#-1,3#3,8,29#8,12#12,15#15,17#17,28#28,29#29,35#35,37#37,40#40,41,57#41,42#42,44#44,45#45,47,53#47,49#49,51#51,53#53,57#57,59,68#59,60#60,62#62,66#66,68#68,72#72,77#77,78#78,79#79,80#80,90#90,94#94,96#96}
```

其中只有`#-10,51,-8`和`#3,29,8`顺序错了。

（2）（问题页网友给出的一个答案）

深度优先遍历。采取递归的手法。比较巧妙。

```
/**
*  author : s2003zy
*  weibo  : http://weibo.com/songzy982
*  blog   : s2003zy.com
*  date   : 2015.02.27
*/
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
       if (!node) return node;
       if(hash.find(node) == hash.end()) {
           hash[node] = new UndirectedGraphNode(node -> label);
           for (auto x : node -> neighbors) {
                (hash[node] -> neighbors).push_back( cloneGraph(x) );
           }
       }
       return hash[node];
    }
};
```

**附录**

**OJ's undirected graph serialization:**

Nodes are labeled uniquely.

We use `#` as a separator for each node, and `,` as a separator for node label and each neighbor of the node.As an example, consider the serialized graph `{0,1,2#1,2#2,2}`.

The graph has a total of three nodes, and therefore contains three parts as separated by `#`.

1.   First node is labeled as `0`. Connect node `0` to both nodes `1` and `2`.

2.   Second node is labeled as `1`. Connect node `1` to node `2`.

3.   Third node is labeled as `2`. Connect node `2` to node `2` (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

```
       1
      / \
     /   \
    0 --- 2
         / \
         \_/
```

