# Time:  O(n)
# Space: O(1)
#
# Given a binary tree, return the postorder traversal of its nodes' values.
#
# For example:
# Given binary tree {1,#,2,3},
#   1
#    \
#     2
#    /
#   3
# return [3,2,1].
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
class Solution:
    # @param root, a tree node
    # @return a list of integers
    def postorderTraversal(self, root):
        dummy = TreeNode(0)
        dummy.left = root
        result, cur = [], dummy
        while cur:
            if cur.left is None:
                prev = cur
                cur = cur.right
            else:
                node = cur.left
                while node.right and node.right != cur:
                    node = node.right
            
                if node.right is None:
                    node.right = cur
                    prev = cur
                    cur = cur.left
                else:
                    result += self.traceBack(cur.left, node)
                    node.right = None
                    prev = cur
                    cur = cur.right
        
        return result
    
    def traceBack(self, frm, to):
        result, cur = [], frm
        while cur is not to:
            result.append(cur.val)
            cur = cur.right
        result.append(to.val)
        result.reverse()
        return result

# Time:  O(n)
# Space: O(n)
# Stack Solution 
class Solution2:
    # @param root, a tree node
    # @return a list of integers
    def postorderTraversal(self, root):
        result, stack, current, last_traversed = [], [], root, None
        while stack or current:
            if current:
                stack.append(current)
                current = current.left
            else:
                parent = stack[-1]
                if parent.right in (None, last_traversed):
                    result.append(parent.val)
                    last_traversed = stack.pop()
                else:
                    current = parent.right
        return result

if __name__ == "__main__":
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)
    result = Solution().postorderTraversal(root)
    print result