# Time:  O(nlogn)
# Space: O(n)

class Solution(object):
    def minimumAbsDifference(self, arr):
        """
        :type arr: List[int]
        :rtype: List[List[int]]
        """
        result = []
        min_diff = float("inf")
        arr.sort()
        for i in xrange(len(arr)-1):
            diff = arr[i+1]-arr[i]
            if diff < min_diff:
                min_diff = diff
                result = [[arr[i], arr[i+1]]]
            elif diff == min_diff:
                result.append([arr[i], arr[i+1]])
        return result
