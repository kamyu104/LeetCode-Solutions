# Time:  O(n)
# Space: O(1)
#
# Given a binary tree, return the inorder traversal of its nodes' values.
#
# For example:
# Given binary tree {1,#,2,3},
#   1
#    \
#     2
#    /
#   3
# return [1,3,2].
#
# Note: Recursive solution is trivial, could you do it iteratively?
#

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# Morris Traversal Solution
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result, prev, cur = [], None, root
        while cur:
            if cur.left is None:
                result.append(cur.val)
                prev = cur
                cur = cur.right
            else:
                node = cur.left
                while node.right and node.right != cur:
                    node = node.right
            
                if node.right is None:
                    node.right = cur
                    cur = cur.left
                else:
                    result.append(cur.val)
                    node.right = None
                    prev = cur
                    cur = cur.right
                
        return result


# Time:  O(n)
# Space: O(h)
# Stack Solution
class Solution2(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result, stack = [], [(root, False)]
        while stack:
            root, is_visited = stack.pop()
            if root is None:
                continue
            if is_visited:
                result.append(root.val)
            else:
                stack.append((root.right, False))
                stack.append((root, True))
                stack.append((root.left, False))
        return result


if __name__ == "__main__":
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)
    result = Solution().inorderTraversal(root)
    print result
