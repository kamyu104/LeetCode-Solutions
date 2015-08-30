# Time:  O(h + k)
# Space: O(h)

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
    
class Solution(object):
    def closestKValues(self, root, target, k):
        """
        :type root: TreeNode
        :type target: float
        :type k: int
        :rtype: List[int]
        """
        stack = []
        self.closestValue(root, target, stack)
        result = [stack[-1].val]
        
        smaller_it, larger_it = BSTIterator(stack), BSTIterator(stack)
        smaller, larger = smaller_it.prev(), larger_it.next()
        while len(result) < k:
            if abs(smaller - target) < abs(larger - target):
                result.append(smaller)
                smaller = smaller_it.prev()
            else:
                result.append(larger)
                larger = larger_it.next()
        return result

    def closestValue(self, root, target, stack):
        """
        :type root: TreeNode
        :type target: float
        :rtype: int
        """
        gap = float("inf")
        closet = float("inf")
        while root:
            stack.append(root)
            if abs(root.val - target) < gap:
                gap = abs(root.val - target)
                closet = root
            if target == root.val:
                return
            elif target < root.val:
                root = root.left
            else:
                root = root.right
        while stack and stack[-1] != closet:
            stack.pop()

class BSTIterator:
    # @param root, a binary search tree's root node
    def __init__(self, stack):
        self.stack = list(stack)
        self.cur = self.stack.pop()

    # @return an integer, the next number
    def next(self):
        node = None
        if self.cur and self.cur.right:
            self.stack.append(self.cur)
            node = self.cur.right
            while node.left:
                self.stack.append(node)
                node = node.left
        elif self.stack:
            prev = self.cur
            node = self.stack.pop();
            while node:
                if node.left is prev:
                    break
                else:
                    prev = node
                    node = self.stack.pop() if self.stack else None
        self.cur = node
        return node.val if node else float("inf")
    
    # @return an integer, the previous number
    def prev(self):
        node = None
        if self.cur and self.cur.left:
            self.stack.append(self.cur)
            node = self.cur.left
            while node.right:
                self.stack.append(node)
                node = node.right
        elif self.stack:
            prev = self.cur
            node = self.stack.pop();
            while node:
                if node.right is prev:
                    break
                else:
                    prev = node
                    node = self.stack.pop() if self.stack else None
        self.cur = node
        return node.val if node else float("-inf")
