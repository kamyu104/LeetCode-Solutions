class Solution(object):
    def maximumSum(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        result, prev, curr = float("-inf"), float("-inf"), float("-inf")
        for x in arr:
            curr = max(prev, curr+x, x)
            result = max(result, curr)
            prev = max(prev+x, x)
        return result
