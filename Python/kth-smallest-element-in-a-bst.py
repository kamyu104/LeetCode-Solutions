# Time:  O(max(h, k))
# Space: O(h)

class Solution(object):
    # @param {TreeNode} root
    # @param {integer} k
    # @return {integer}
    def kthSmallest(self, root, k):
        s, cur, rank = [], root, 0

        while s or cur:
            if cur:
                s.append(cur)
                cur = cur.left
            else:
                cur = s.pop()
                rank += 1
                if rank == k:
                    return cur.val
                cur = cur.right

        return float("-inf")


# time: O(max(h, k))
# space: O(h)

from itertools import islice


class Solution2(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        def gen_inorder(root):
            if root:
                for n in gen_inorder(root.left):
                    yield n

                yield root.val

                for n in gen_inorder(root.right):
                    yield n

        return next(islice(gen_inorder(root), k-1, k))

# time: O(h)
# space: O(h)
class Solution3(object):
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        # This list will store the inorder traversal
        inorder_nodes = []

        # Helper function to perform inorder traversal
        def inorder(node):
            if not node:
                return
            # Visit left subtree
            inorder(node.left)
            # Visit current node
            inorder_nodes.append(node.val)
            # Visit right subtree
            inorder(node.right)

        # Perform inorder traversal starting from root
        inorder(root)

        # kth smallest is the (k-1)th element in 0-indexed list
        return inorder_nodes[k - 1]
