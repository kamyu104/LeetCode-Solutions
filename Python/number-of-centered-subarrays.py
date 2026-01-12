# Time:  O(n^2)
# Space: O(n)

# hash table
class Solution(object):
    def centeredSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for i in xrange(len(nums)):
            lookup = set()
            total = 0
            for j in xrange(i, len(nums)):
                lookup.add(nums[j])
                total += nums[j]
                if total in lookup:
                    result += 1
        return result
