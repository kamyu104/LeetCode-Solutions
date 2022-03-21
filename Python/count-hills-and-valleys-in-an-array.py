# Time:  O(n)
# Space: O(1)

# simulation, array
class Solution(object):
    def countHillValley(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result, inc = 0, -1
        for i in xrange(len(nums)-1):
            if nums[i] < nums[i+1]:
                result += int(inc == 0)
                inc = 1
            elif nums[i] > nums[i+1]:
                result += int(inc == 1)
                inc = 0
        return result
