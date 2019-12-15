# Time:  O((8 + 1) * 8 / 2) = O(1)
# Space: O(8) = O(1)

import collections


class Solution(object):
    def sequentialDigits(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: List[int]
        """
        result = []
        q = collections.deque(range(1, 9))
        while q:
            num = q.popleft()
            if num > high:
                continue
            if low <= num:
                result.append(num)
            if num%10+1 < 10:
                q.append(num*10+num%10+1)
        return result
