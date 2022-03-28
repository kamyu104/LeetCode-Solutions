# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def minDeletion(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for i in xrange(len(nums)-1):
            result += int(i%2 == result%2 and nums[i] == nums[i+1])
        return result+(len(nums)-result)%2
