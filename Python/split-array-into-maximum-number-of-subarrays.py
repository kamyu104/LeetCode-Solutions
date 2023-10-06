# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def maxSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = curr = 0
        for x in nums:
            curr = curr&x if curr else x
            if not curr:
                result += 1
        return max(result, 1)
