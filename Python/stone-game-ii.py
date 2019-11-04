# Time:  O(n*(logn)^2)
# Space: O(nlogn)

class Solution(object):
    def stoneGameII(self, piles):
        """
        :type piles: List[int]
        :rtype: int
        """
        def dp(piles, lookup, i, m):
            if i+2*m >= len(piles):
                return piles[i]
            if (i, m) not in lookup:
                lookup[i, m] = piles[i] - \
                               min(dp(piles, lookup, i+x, max(m, x))
                                   for x in xrange(1, 2*m+1))
            return lookup[i, m]

        for i in reversed(xrange(len(piles)-1)):
            piles[i] += piles[i+1]
        return dp(piles, {}, 0, 1)
