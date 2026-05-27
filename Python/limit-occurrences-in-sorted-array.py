# Time:  O(n)
# Space: O(1)

# array, inplace
class Solution(object):
    def limitOccurrences(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        i = 0
        for x in nums:
            if i-k >= 0 and nums[i-k] == x:
                continue
            nums[i] = x
            i += 1
        while len(nums) != i:
            nums.pop()
        return nums
