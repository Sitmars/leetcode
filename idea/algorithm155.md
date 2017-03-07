## 155. Min Stack

**题目 :**

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

- push(x) -- Push element x onto stack.
- pop() -- Removes the element on top of the stack.
- top() -- Get the top element.
- getMin() -- Retrieve the minimum element in the stack.

**Example:**

```
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
```

**题意 :**

手动实现一个栈，要求具有压栈、出栈、返回栈顶元素、返回最小元素四个功能。

**思路 :**

本身是个简单题。用calloc开一个整型数组，再用一个整型指针指向它。当长度不够时再开一个更大的，把原来的元素复制进去。问题的关键在于，是否愿意牺牲空间来保存每一步的最小值。如果不愿意，就现场求；空间无所谓，就保存一下。

还有就是，这种实现速度并不快。看了别人一个简单的答案，可能会快。但是他居然是用stack实现的，用stack实现一个自己的stack？感觉挺没意义的。