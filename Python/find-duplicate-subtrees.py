# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def findDuplicateSubtrees(self, root):
        """
        :type root: TreeNode
        :rtype: List[TreeNode]
        """
        def getid(root, lookup, trees):
            if not root:
                return -1
            node_id = lookup[root.val,
                             getid(root.left, lookup, trees),
                             getid(root.right, lookup, trees)]
            trees[node_id].append(root)
            return node_id

        trees = collections.defaultdict(list)
        lookup = collections.defaultdict()
        lookup.default_factory = lookup.__len__
        getid(root, lookup, trees)
        return [roots[0] for roots in trees.itervalues() if len(roots) > 1]


# Time:  O(n * h)
# Space: O(n * h)
class Solution2(object):
    def findDuplicateSubtrees(self, root):
        """
        :type root: TreeNode
        :rtype: List[TreeNode]
        """
        def postOrderTraversal(node, lookup, result):
            if not node:
                return ""
            s = "(" + postOrderTraversal(node.left, lookup, result) + \
                str(node.val) + \
                postOrderTraversal(node.right, lookup, result) + \
                ")"
            if lookup[s] == 1:
                result.append(node)
            lookup[s] += 1
            return s

        lookup = collections.defaultdict(int)
        result = []
        postOrderTraversal(root, lookup, result)
        return result

