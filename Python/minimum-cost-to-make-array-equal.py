# Time:  O(nlogn)
# Space: O(1)

import itertools


# math, binary search
class Solution(object):
    def minCost(self, nums, cost):
        """
        :type nums: List[int]
        :type cost: List[int]
        :rtype: int
        """
        def check(x, t):
            return sum(c for y, c in itertools.izip(nums, cost) if y <= x) >= t
    
        total = sum(cost)
        left, right = min(nums), max(nums)
        median = (total+1)//2
        while left <= right:
            mid = left+(right-left)//2
            if check(mid, median):
                right = mid-1
            else:
                left = mid+1
        return sum(abs(x-left)*c for x, c in itertools.izip(nums, cost))
