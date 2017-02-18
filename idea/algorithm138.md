## 138. Copy List with Random Pointer

**题目 :**

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

**题意 :**

现有一个链表，每个节点除了有指向下一个节点的next指针以外，还有一个指向随机节点或null的random指针。

请返回这个链表的深拷贝。

**思路 :**

（1）广度优先遍历。

用一个队列保存遇到却没来得及访问的指针。从head指针开始，每遍历到一个原始链表节点，就建立一个与之对应的新链表节点，并将原始节点的next、random指针加入队列。同时需要一个队列来保存各个next/random指针的所属节点，以便连接节点。最后还需要建立一个从原始节点到新节点的映射。

（2）遍历三遍链表：（题目页点赞最多的答案）

第一次只遍历next指针。在创建对应新节点的同时将原始、新两个链表交叉着连在一起；

```
        ------       ------       ------       ------      
origin  |  1  |     |  2  |      |  3  |      |  4  |     null
        ------     - ------     - ------     - ------     -
           |      -    |       -    |       -     |      -
        ------   -   ------   -   ------   -   ------   -   
  new   |  1  | -   |  2  |  -   |  3  |  -   |  4  |  -
        ------       ------       ------       ------      
```

第二次只遍历random指针。在新节点中复制随机指针。重要算法公式：

`origin.next.random = origin.random.next`

第三次遍历分离这两个链表。

这种方法的好处在于不需要多余的空间在保存指针，将空间复杂度降到O(1)。