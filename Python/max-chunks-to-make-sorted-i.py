# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        result, max_i = 0, 0
        for i, v in enumerate(arr):
            max_i = max(max_i, v)
            if max_i == i:
                result += 1
        return result
