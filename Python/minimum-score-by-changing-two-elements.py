# Time:  O(nlogn)
# Space: O(1)

# sort, greedy
class Solution(object):
    def minimizeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        return min(nums[-3+i]-nums[i] for i in xrange(3))
