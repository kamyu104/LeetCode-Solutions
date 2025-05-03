# Time:  O(nlogn * logr)
# Space: O(n)

from sortedcontainers import SortedList


# binary search, sorted list
class Solution(object):
    def minThreshold(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def binary_search(left, right, check):
            while left <= right:
                mid = left + (right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def check(x):
            sl = SortedList()
            cnt = 0
            for i in reversed(nums):
                cnt += sl.bisect_left(i)-sl.bisect_left(i-x)
                sl.add(i)
            return cnt >= k

        mx, right = nums[0], 0
        for i in xrange(1, len(nums)):
            right = max(right, mx-nums[i])
            mx = max(mx, nums[i])
        result = binary_search(0, right, check)
        return result if result <= right else -1
