# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def minAbsoluteDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        INF = float("inf")
        result = INF
        i = j = -1
        for k in xrange(len(nums)):
            if nums[k] == 0:
                continue
            if nums[k] == 1:
                i = k
            else:
                j = k
            if i != -1 != j:
                result = min(result, abs(i-j))
        return result if result is not INF else -1
