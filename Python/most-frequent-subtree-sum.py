# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def findFrequentTreeSum(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        def countSubtreeSumHelper(root, counts):
            if not root:
                return 0
            total = root.val + \
                    countSubtreeSumHelper(root.left, counts) + \
                    countSubtreeSumHelper(root.right, counts)
            counts[total] += 1
            return total

        counts = collections.defaultdict(int)
        countSubtreeSumHelper(root, counts)
        max_count = max(counts.values()) if counts else 0
        return [total for total, count in counts.iteritems() if count == max_count]

