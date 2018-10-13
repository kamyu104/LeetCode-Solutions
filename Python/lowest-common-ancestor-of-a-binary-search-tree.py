# Time:  O(n)
# Space: O(1)

class Solution(object):
    # @param {TreeNode} root
    # @param {TreeNode} p
    # @param {TreeNode} q
    # @return {TreeNode}
    def lowestCommonAncestor(self, root, p, q):
        s, b = sorted([p.val, q.val])
        while not s <= root.val <= b:
            # Keep searching since root is outside of [s, b].
            root = root.left if s <= root.val else root.right
        # s <= root.val <= b.
        return root

