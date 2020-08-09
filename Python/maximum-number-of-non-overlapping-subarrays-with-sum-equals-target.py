# Time:  O(n)
# Space: O(n)

class Solution(object):
    def maxNonOverlapping(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        lookup = {0:-1}
        result, accu, right = 0, 0, -1
        for i, num in enumerate(nums):
            accu += num
            if accu-target in lookup and lookup[accu-target] >= right:
                right = i
                result += 1  # greedy
            lookup[accu] = i
        return result
