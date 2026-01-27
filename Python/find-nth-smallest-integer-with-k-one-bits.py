# Time:  ctor:    O(r^2)
#        runtime: O(r)
# Space: O(r^2)

# dp, combinatorics
MAX_K = 50
DP = [[0]*(MAX_K+1) for _ in xrange(MAX_K+1)]
for i in xrange(MAX_K+1):
    DP[i][0] = 1
    for j in xrange(1, i+1):
        DP[i][j] = DP[i-1][j-1]+DP[i-1][j]
class Solution(object):
    def nthSmallest(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        result = 0
        for i in reversed(xrange(MAX_K)):
            if n <= DP[i][k]:
                continue
            n -= DP[i][k]
            result |= 1<<i
            k -= 1
            if not k:
                break
        return result
