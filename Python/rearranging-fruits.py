# Time:  O(n) on average
# Space: O(n)

import random
import collections


# freq table, greedy, quick select
class Solution(object):
    def minCost(self, basket1, basket2):
        """
        :type basket1: List[int]
        :type basket2: List[int]
        :rtype: int
        """
        def nth_element(nums, n, left=0, compare=lambda a, b: a < b):
            def tri_partition(nums, left, right, target, compare):
                mid = left
                while mid <= right:
                    if nums[mid] == target:
                        mid += 1
                    elif compare(nums[mid], target):
                        nums[left], nums[mid] = nums[mid], nums[left]
                        left += 1
                        mid += 1
                    else:
                        nums[mid], nums[right] = nums[right], nums[mid]
                        right -= 1
                return left, right
            
            right = len(nums)-1
            while left <= right:
                pivot_idx = random.randint(left, right)
                pivot_left, pivot_right = tri_partition(nums, left, right, nums[pivot_idx], compare)
                if pivot_left <= n <= pivot_right:
                    return
                elif pivot_left > n:
                    right = pivot_left-1
                else:  # pivot_right < n.
                    left = pivot_right+1
    
        cnt = collections.Counter()
        for x in basket1:
            cnt[x] += 1
        for x in basket2:
            cnt[x] -= 1
        mn = min(cnt.iterkeys())
        swaps = []
        for k, v in cnt.iteritems():
            if v%2:
                return -1
            swaps.extend(k for _ in xrange(abs(v)//2))
        nth_element(swaps, len(swaps)//2)
        return sum(min(swaps[i], mn*2) for i in xrange(len(swaps)//2))
