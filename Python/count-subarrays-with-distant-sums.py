# Time:  O(nlogn)
# Space: O(n)

from sortedcontainers import SortedList


# prefix sum, sorted list
class Solution(object):
    def distantSubarrays(self, nums, goal, k):
        """
        :type nums: List[int]
        :type goal: int
        :type k: int
        :rtype: int
        """
        if k == 0:
            return (len(nums)+1)*len(nums)//2
        result = prefix = 0
        sl = SortedList([0])
        for x in nums:
            prefix += x
            result += sl.bisect_right(prefix-(goal+k))+(len(sl)-sl.bisect_left(prefix-(goal-k)))
            sl.add(prefix)
        return result


# Time:  O(nlogn)
# Space: O(n)
import bisect


# prefix sum, bit
class BIT(object):  # 0-indexed.
    def __init__(self, n):
        self.__bit = [0]*(n+1)  # Extra one for dummy node.

    def add(self, i, val):
        i += 1  # Extra one for dummy node.
        while i < len(self.__bit):
            self.__bit[i] += val
            i += (i & -i)

    def query(self, i):
        i += 1  # Extra one for dummy node.
        ret = 0
        while i > 0:
            ret += self.__bit[i]
            i -= (i & -i)
        return ret


class Solution2(object):
    def distantSubarrays(self, nums, goal, k):
        """
        :type nums: List[int]
        :type goal: int
        :type k: int
        :rtype: int
        """
        if k == 0:
            return (len(nums)+1)*len(nums)//2
        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix[i+1] = prefix[i]+nums[i]
        vals = sorted(set(prefix))
        val_to_idx = {x: i for i, x in enumerate(vals)}
        bit = BIT(len(vals))
        bit.add(val_to_idx[0], 1) 
        result = 0
        for i in xrange(len(nums)):
            result += bit.query(bisect.bisect_right(vals, prefix[i+1]-(goal+k))-1)
            result += (i+1)-bit.query(bisect.bisect_left(vals, prefix[i+1]-(goal-k))-1)
            bit.add(val_to_idx[prefix[i+1]], 1)
        return result
