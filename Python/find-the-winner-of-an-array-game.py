# Time:  O(n)
# Space: O(1)

class Solution(object):
    def getWinner(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: int
        """
        result = arr[0]
        count = 0
        for i in xrange(1, len(arr)):
            if arr[i] > result:
                result = arr[i]
                count = 0
            count += 1
            if (count == k):
                break
        return result
