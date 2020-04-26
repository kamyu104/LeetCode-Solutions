# Time:  O(m * n)
# Space: O(m)

import itertools


class Solution(object):
    def findDiagonalOrder(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
        result, q, col = [], [], 0
        for i in xrange(len(nums)+max(itertools.imap(len, nums))-1):
            new_q = []
            if i < len(nums):
                q.append((i, 0))
            for r, c in reversed(q):
                result.append(nums[r][c])
                if c+1 < len(nums[r]):
                    new_q.append((r, c+1))
            new_q.reverse()
            q = new_q
        return result


# Time:  O(m * n)
# Space: O(m * n)
class Solution2(object):
    def findDiagonalOrder(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
        result = []
        for r, row in enumerate(nums):
            for c, num in enumerate(row):
                if len(result) <= r+c:
                    result.append([])
                result[r+c].append(num)
        return [num for row in result for num in reversed(row)]
