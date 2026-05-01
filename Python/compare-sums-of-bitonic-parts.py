# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def compareBitonicSums(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        total = 0
        for i in xrange(len(nums)-1):
            if nums[i] < nums[i+1]:
                total += nums[i]
            elif nums[i] > nums[i+1]:
                total -= nums[i+1]
        return 0 if total > 0 else 1 if total < 0 else -1
