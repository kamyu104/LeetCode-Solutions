# Time:  O(n)
# Space: O(n)

import collections

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3

class Solution(object):
    def verticalOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        cols = collections.defaultdict(list)
        queue = [(root, 0)]
        for node, i in queue:
            if node:
                cols[i].append(node.val)
                queue += (node.left, i - 1), (node.right, i + 1)
        return [cols[i] for i in xrange(min(cols.keys()),
                                        max(cols.keys()) + 1)] if cols else []

