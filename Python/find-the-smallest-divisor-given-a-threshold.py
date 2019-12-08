# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def smallestDivisor(self, nums, threshold):
        """
        :type nums: List[int]
        :type threshold: int
        :rtype: int
        """
        def check(A, d, threshold):
            return sum((i-1)//d+1 for i in nums) <= threshold

        left, right = 1, max(nums)
        while left <= right:
            mid = left + (right-left)//2
            if check(nums, mid, threshold):
                right = mid-1
            else:
                left = mid+1
        return left
