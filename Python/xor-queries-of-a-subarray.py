# Time:  O(n)
# Space: O(1)

class Solution(object):
    def xorQueries(self, arr, queries):
        """
        :type arr: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        for i in xrange(1, len(arr)):
            arr[i] ^= arr[i-1]
        return [arr[right] ^ arr[left-1] if left else arr[right] for left, right in queries]
