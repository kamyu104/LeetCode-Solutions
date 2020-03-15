# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def balanceBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def inorderTraversal(root):
            result, stk = [], [(root, False)]
            while stk:
                node, is_visited = stk.pop()
                if node is None:
                    continue
                if is_visited:
                    result.append(node.val)
                else:
                    stk.append((node.right, False))
                    stk.append((node, True))
                    stk.append((node.left, False))
            return result
    
        def orderedArrayToBst(arr):
            ROOT, LEFT, RIGHT = range(3)
            result = [None]
            stk = [(0, len(arr), ROOT, result)]
            while stk:
                i, j, update, ret = stk.pop()
                if i >= j:
                    continue
                mid = i + (j-i)//2
                node = TreeNode(arr[mid])
                if update == ROOT:
                    ret[0] = node
                elif update == LEFT:
                    ret[0].left = node
                else:
                    ret[0].right = node
                stk.append((mid+1, j, RIGHT, [node]))
                stk.append((i, mid, LEFT, [node]))
            return result[0]
        
        return orderedArrayToBst(inorderTraversal(root))


# Time:  O(n)
# Space: O(h)
class Solution2(object):
    def balanceBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def inorderTraversal(root):
            def inorderTraversalHelper(node, arr):
                if not node:
                    return
                inorderTraversalHelper(node.left, arr)
                arr.append(node.val)
                inorderTraversalHelper(node.right, arr)

            arr = []
            inorderTraversalHelper(root, vals)
            return arr
        
        def orderedArrayToBst(arr, i, j):
            if i >= j:
                return None
            mid = i + (j-i)//2
            return TreeNode(arr[mid],
                            orderedArrayToBst(arr, i, mid),
                            orderedArrayToBst(arr, mid+1, j))
        
        arr = inorderTraversal(root)
        return orderedArrayToBst(arr, 0, len(arr))
