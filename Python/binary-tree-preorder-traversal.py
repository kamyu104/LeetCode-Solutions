# Time:  O(n)
# Space: O(n)
#
# Given a binary tree, return the preorder traversal of its nodes' values.
#
# For example:
# Given binary tree {1,#,2,3},
#    1
#     \
#      2
#     /
#    3
# return [1,2,3].
#
# Note: Recursive solution is trivial, could you do it iteratively?
#

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def preorderTraversal(self, root):
        result, stack, current, last_traversed = [], [], root, None
        while stack or current:
            if current:
                result.append(current.val)
                stack.append(current)
                current = current.left
            else:
                parent = stack[-1]
                if parent.right in (None, last_traversed):
                    last_traversed = stack.pop()
                else:
                    current = parent.right
        return result

if __name__ == "__main__":
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)
    result = Solution().preorderTraversal(root)
    print result