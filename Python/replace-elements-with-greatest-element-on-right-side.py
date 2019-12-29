# Time:  O(n)
# Space: O(1)

class Solution(object):
    def replaceElements(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        curr_max = -1
        for i in reversed(xrange(len(arr))):
            arr[i], curr_max = curr_max, max(curr_max, arr[i])
        return arr
