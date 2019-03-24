# Time:  O(n^2), n is the length of S
# Space: O(1)

class Solution(object):
    def queryString(self, S, N):
        """
        :type S: str
        :type N: int
        :rtype: bool
        """
        # since S with length n has at most different n-k+1 k-digit numbers
        # => given S with length n, valid N is at most 2(n-k+1)
        # => valid N <= 2(n-k+1) < 2n = 2 * S.length
        return all(bin(i)[2:] in S for i in reversed(xrange(N//2, N+1)))
