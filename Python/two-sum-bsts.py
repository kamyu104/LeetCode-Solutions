# Time:  O(n)
# Space: O(n)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def twoSumBSTs(self, root1, root2, target):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :type target: int
        :rtype: bool
        """
        def inorder_gen(root, asc=True):
            result, stack = [], [(root, False)]
            while stack:
                root, is_visited = stack.pop()
                if root is None:
                    continue
                if is_visited:
                    yield root.val
                else:
                    if asc:
                        stack.append((root.right, False))
                        stack.append((root, True))
                        stack.append((root.left, False))
                    else:
                        stack.append((root.left, False))
                        stack.append((root, True))
                        stack.append((root.right, False))
        
        left_gen, right_gen = inorder_gen(root1, True), inorder_gen(root2, False)
        left, right = next(left_gen), next(right_gen)
        while left is not None and right is not None:
            if left + right < target:
                left = next(left_gen)
            elif left + right > target:
                right = next(right_gen)
            else:
                return True
        return False
