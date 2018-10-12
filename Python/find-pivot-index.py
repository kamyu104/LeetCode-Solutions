# Time:  O(n)
# Space: O(1)

class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        total = sum(nums)
        left_sum = 0
        for i, num in enumerate(nums):
            if left_sum == (total-left_sum-num):
                return i
            left_sum += num
        return -1


