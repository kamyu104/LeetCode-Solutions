# Time:  O(nlogr)
# Space: O(n)

import random


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


# greedy, quick select
class Solution(object):
    def maximizeSum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def f(n):
            cnt = [0]*10
            x = n
            while x:
                x, r = divmod(x, 10)
                cnt[r] += 1
            d = 0
            for i in reversed(xrange(len(cnt))):
                for _ in xrange(cnt[i]):
                    d = d*10+i
            return d-n

        result = sum(nums)
        candidates = [f(x) for x in nums]
        nth_element(candidates, k-1, compare=lambda a, b: a > b)
        return sum(nums)+sum(candidates[i] for i in xrange(k))


# Time:  O(n * (logr) * log(logr) + nlogn)
# Space: O(n + logr)
# greedy, sort
class Solution2(object):
    def maximizeSum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def f(n):
            return int("".join(sorted(str(n)))[::-1])-n

        candidates = sorted((f(x) for x in nums), reverse=True)
        return sum(nums)+sum(candidates[i] for i in xrange(k))
