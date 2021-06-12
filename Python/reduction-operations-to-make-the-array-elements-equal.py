# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def reductionOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        result = curr = 0
        for i in xrange(1, len(nums)): 
            if nums[i-1] < nums[i]:
                curr += 1
            result += curr
        return result
