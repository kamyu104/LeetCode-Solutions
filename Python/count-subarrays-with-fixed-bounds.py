# Time:  O(n)
# Space: O(1)

# two pointers
class Solution(object):
    def countSubarrays(self, nums, minK, maxK):
        """
        :type nums: List[int]
        :type minK: int
        :type maxK: int
        :rtype: int
        """
        result = left = 0
        right = [-1]*2
        for i, x in enumerate(nums):
            if not (minK <= x <= maxK):
                left = i+1
                continue
            if x == minK:
                right[0] = i
            if x == maxK:
                right[1] = i
            result += max(min(right)-left+1, 0)
        return result
