# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maxValueAfterReverse(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result, add, max_pair, min_pair = 0, 0, float("-inf"), float("inf")
        for i in xrange(1, len(nums)):
            result += abs(nums[i-1]-nums[i])
            add = max(add,
                      abs(nums[0]-nums[i]) - abs(nums[i-1]-nums[i]),
                      abs(nums[-1]-nums[i-1]) - abs(nums[i-1]-nums[i]))
            min_pair = min(min_pair, max(nums[i-1], nums[i]))
            max_pair = max(max_pair, min(nums[i-1], nums[i]))
        return result + max(add, (max_pair-min_pair)*2)
