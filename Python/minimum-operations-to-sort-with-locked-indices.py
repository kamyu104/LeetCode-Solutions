# Time:  O(nlogn)
# Space: O(n)

# fenwick tree
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


class Solution(object):
    def minOperations(self, nums, locked, k):
        """
        :type nums: List[int]
        :type locked: List[int]
        :type k: int
        :rtype: int
        """
        cnt = inv = 0
        mn = len(nums)+1
        bit = BIT(len(nums))
        for i in reversed(xrange(len(nums))):
            if mn < i+2 or min(mn, nums[i]) < i+1:
                cnt += locked[i]
            mn = min(mn, nums[i])
            inv += bit.query(nums[i]-1)
            bit.add(nums[i], 1)
        return cnt+inv if cnt <= k else -1
    

# Time:  O(nlogn)
# Space: O(n)
# sorted list
from sortedcontainers import SortedList


class Solution2(object):
    def minOperations(self, nums, locked, k):
        """
        :type nums: List[int]
        :type locked: List[int]
        :type k: int
        :rtype: int
        """
        cnt = inv = 0
        mn = len(nums)+1
        sl = SortedList()
        for i in reversed(xrange(len(nums))):
            if mn < i+2 or min(mn, nums[i]) < i+1:
                cnt += locked[i]
            mn = min(mn, nums[i])
            inv += sl.bisect_left(nums[i])
            sl.add(nums[i])
        return cnt+inv if cnt <= k else -1
