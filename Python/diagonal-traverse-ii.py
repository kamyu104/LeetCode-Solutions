# Time:  O(m * n)
# Space: O(m)

import itertools
import collections


class Solution(object):
    def findDiagonalOrder(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
        result, dq, col = [], collections.deque(), 0
        for i in xrange(len(nums)+max(itertools.imap(len, nums))-1):
            new_dq = collections.deque()
            if i < len(nums):
                dq.appendleft((i, 0))
            for r, c in dq:
                result.append(nums[r][c])
                if c+1 < len(nums[r]):
                    new_dq.append((r, c+1))
            dq = new_dq
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
