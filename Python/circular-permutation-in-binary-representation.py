# Time:  O(2^n)
# Space: O(1)

class Solution(object):
    def circularPermutation(self, n, start):
        """
        :type n: int
        :type start: int
        :rtype: List[int]
        """
        return [start ^ (i>>1) ^ i for i in xrange(1<<n)]
