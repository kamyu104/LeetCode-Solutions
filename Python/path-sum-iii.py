# Time:  O(n)
# Space: O(h)

import collections


class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        def pathSumHelper(root, curr, sum, lookup):
            if root is None:
                return 0
            curr += root.val
            result = lookup[curr-sum] if curr-sum in lookup else 0
            lookup[curr] += 1
            result += pathSumHelper(root.left, curr, sum, lookup) + \
                      pathSumHelper(root.right, curr, sum, lookup)
            lookup[curr] -= 1
            if lookup[curr] == 0:
                del lookup[curr]
            return result

        lookup = collections.defaultdict(int)
        lookup[0] = 1
        return pathSumHelper(root, 0, sum, lookup)


# Time:  O(n^2)
# Space: O(h)
class Solution2(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        def pathSumHelper(root, prev, sum):
            if root is None:
                return 0

            curr = prev + root.val
            return int(curr == sum) + \
                   pathSumHelper(root.left, curr, sum) + \
                   pathSumHelper(root.right, curr, sum)

        if root is None:
            return 0

        return pathSumHelper(root, 0, sum) + \
               self.pathSum(root.left, sum) + \
               self.pathSum(root.right, sum)

