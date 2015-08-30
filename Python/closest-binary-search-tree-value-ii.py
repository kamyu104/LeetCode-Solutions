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
        node = self.closestValue(root, target, stack)
        result = [node.val]
        
        smaller_it, larger_it = BSTIterator(node, stack), BSTIterator(node, stack)
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
                closet = stack.pop()
                break
            elif target < root.val:
                root = root.left
            else:
                root = root.right
        return closet


class BSTIterator:
    # @param root, a binary search tree's root node
    def __init__(self, cur, stack):
        self.stack = list(stack)
        self.cur = cur

    # @return an integer, the next number
    def next(self):
        node = None
        if self.cur and self.cur.right:
            node = self.cur.right
            while node.left:
                self.stack.append(node)
                node = node.left
        elif self.stack:
            node = self.stack.pop();
            while node:
                if node.val > self.cur.val:
                   break
                else:
                   node = self.stack.pop() if self.stack else None
        self.cur = node
        return node.val if node else float("inf")
    
    # @return an integer, the previous number
    def prev(self):
        node = None
        if self.cur and self.cur.left:
            node = self.cur.left
            while node.right:
                self.stack.append(node)
                node = node.right
        elif self.stack:
            node = self.stack.pop();
            while node:
                if node.val < self.cur.val:
                   break
                else:
                   node = self.stack.pop() if self.stack else None
        self.cur = node
        return node.val if node else float("-inf")
