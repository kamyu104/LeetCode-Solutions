# Time:  O(n)
# Space: O(n)

# hash table
class Solution(object):
    def findSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        lookup = set()
        for i in xrange(len(nums)-1):
            if nums[i]+nums[i+1] in lookup:
                return True
            lookup.add(nums[i]+nums[i+1])
        return False
