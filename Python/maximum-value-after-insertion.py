# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maxValue(self, n, x):
        """
        :type n: str
        :type x: int
        :rtype: str
        """
        check = (lambda i: str(x) > n[i]) if n[0] != '-' else (lambda i: str(x) < n[i])
        for i in xrange(len(n)):
            if check(i):
                break
        else:
            i = len(n)
        return n[:i] + str(x) + n[i:]
