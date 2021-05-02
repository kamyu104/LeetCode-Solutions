# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def maximumElementAfterDecrementingAndRearranging(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        arr.sort()
        result = 1
        for i in xrange(1, len(arr)):
            result = min(result+1, arr[i])
        return result
