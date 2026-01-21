# Time:  O(n)
# Space: O(n)

# hash table
class Solution(object):
    def minOperations(self, nums, target):
        """
        :type nums: List[int]
        :type target: List[int]
        :rtype: int
        """
        return len(set(nums[i]for i in xrange(len(nums)) if nums[i] != target[i]))
