# Time:  O(n)
# Space: O(n)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        pass


class Solution(object):
    def canMerge(self, trees):
        """
        :type trees: List[TreeNode]
        :rtype: TreeNode
        """
        def find_leaves_and_roots(trees, leaf_vals_set, val_to_root):
            for root in trees:
                val_to_root[root.val] = root
                q = [root]
                while q:
                    new_q = []
                    for node in q:
                        if node.left is None and node.right is None:
                            if node is not root:
                                leaf_vals_set.add(node.val)
                            continue
                        if node.left:
                            new_q.append(node.left)
                        if node.right:
                            new_q.append(node.right)
                    q = new_q

        def find_root(trees, left_vals_set, val_to_root):
            root = None
            for node in trees:
                if node.val in leaf_vals_set:
                    continue
                if root:  # multiple roots
                    return None
                root = node
            return root

        def merge_bsts(root, left_vals_set, val_to_root):
            if not root:
                return None
            del val_to_root[root.val]
            q = [(root, float("-inf"), float("inf"))]
            while q:
                new_q = []
                for node, left, right in q:
                    if not (left < node.val < right):
                        return None
                    if node.left:
                        if node.left.val in leaf_vals_set and node.left.val in val_to_root:
                            node.left = val_to_root[node.left.val]
                            del val_to_root[node.left.val]
                        new_q.append((node.left, left, node.val))
                    if node.right:
                        if node.right.val in leaf_vals_set and node.right.val in val_to_root:
                            node.right = val_to_root[node.right.val]
                            del val_to_root[node.right.val]
                        new_q.append((node.right, node.val, right))
                q = new_q
            return root if not val_to_root else None

        leaf_vals_set, val_to_root = set(), {}
        find_leaves_and_roots(trees, leaf_vals_set, val_to_root)    
        root = find_root(trees, leaf_vals_set, val_to_root)
        return merge_bsts(root, leaf_vals_set, val_to_root)
