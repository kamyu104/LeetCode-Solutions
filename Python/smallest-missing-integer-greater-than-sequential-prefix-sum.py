# Time:  O(n)
# Space: O(n)

# hash table
class Solution(object):
    def missingInteger(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        total = nums[0]
        for i in xrange(1, len(nums)):
            if nums[i] != nums[i-1]+1:
                break
            total += nums[i]
        lookup = set(nums)
        while total in lookup:
            total += 1
        return total
