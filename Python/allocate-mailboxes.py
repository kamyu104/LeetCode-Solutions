# Time:  O(m * n^2)
# Space: O(n)

class Solution(object):
    def minDistance(self, houses, k):
        """
        :type houses: List[int]
        :type k: int
        :rtype: int
        """
        def cost(prefix, i, j):
            return (prefix[j+1]-prefix[(i+j+1)//2])-(prefix[(i+j)//2+1]-prefix[i])

        houses.sort()
        prefix = [0]*(len(houses)+1)
        for i, h in enumerate(houses):
            prefix[i+1] = prefix[i]+h
        dp = [cost(prefix, 0, j) for j in xrange(len(houses))]
        for m in xrange(1, k):
            for j in reversed(xrange(m, len(houses))):
                for i in xrange(m, j+1):
                    dp[j] = min(dp[j], dp[i-1]+cost(prefix, i, j))
        return dp[-1]
