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


# Time:  O(nlogn)
# Space: O(n)
# prefix sum
class Solution2(object):
    def minCost(self, nums, cost):
        """
        :type nums: List[int]
        :type cost: List[int]
        :rtype: int
        """
        idxs = range(len(nums))
        idxs.sort(key=lambda x: nums[x])
        prefix = [0]*(len(cost)+1)
        left = 0
        for i in xrange(len(cost)):
            if i-1 >= 0:
                left += prefix[i]*(nums[idxs[i]]-nums[idxs[i-1]])
            prefix[i+1] = prefix[i]+cost[idxs[i]]
        result = float("inf")
        suffix = right = 0
        for i in reversed(xrange(len(cost))):
            if i+1 < len(idxs):
                right += suffix*(nums[idxs[i+1]]-nums[idxs[i]])
            result = min(result, left+right)
            if i-1 >= 0:
                left -= prefix[i]*(nums[idxs[i]]-nums[idxs[i-1]])
            suffix += cost[idxs[i]]
        return result
