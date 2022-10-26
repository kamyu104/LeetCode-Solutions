# Time:  O(nlogn)
# Space: O(n)

import itertools


# math, binary search
class Solution(object):
    def minCost(self, nums, cost):
        """
        :type nums: List[int]
        :type cost: List[int]
        :rtype: int
        """
        def f(x):
            return sum(abs(y-x)*c for y, c in itertools.izip(nums, cost))

        def check(x, t):
            return sum(c for y, c in itertools.izip(nums, cost) if y <= x) >= t
    
        idxs = range(len(nums))
        idxs.sort(key=lambda x: nums[x])
        left, right = 0, len(idxs)-1
        total = sum(cost)
        median = (total+1)//2
        while left <= right:
            mid = left+(right-left)//2
            if check(nums[idxs[mid]], median):
                right = mid-1
            else:
                left = mid+1
        return f(nums[idxs[left]])


# Time:  O(nlogn)
# Space: O(n)
import itertools


# binary search
class Solution2(object):
    def minCost(self, nums, cost):
        """
        :type nums: List[int]
        :type cost: List[int]
        :rtype: int
        """
        def f(x):
            return sum(abs(y-x)*c for y, c in itertools.izip(nums, cost))
    
        def check(x):
            return x+1 == len(idxs) or f(nums[idxs[x]]) < f(nums[idxs[x+1]])

        idxs = range(len(nums))
        idxs.sort(key=lambda x: nums[x])
        left, right = 0, len(idxs)-1
        while left <= right:
            mid = left+(right-left)//2
            if check(mid):
                right = mid-1
            else:
                left = mid+1
        return f(nums[idxs[left]])


# Time:  O(nlogn)
# Space: O(n)
# prefix sum
class Solution3(object):
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
