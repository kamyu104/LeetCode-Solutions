# Time:  O(min(n * k^2, m * k)), m = sum(len(pile) for pile in piles)
# Space: O(k)

# dp
class Solution(object):
    def maxValueOfCoins(self, piles, k):
        """
        :type piles: List[List[int]]
        :type k: int
        :rtype: int
        """
        dp = [0]
        for pile in piles:
            new_dp = [0]*min(len(dp)+len(pile), k+1)
            for i in xrange(len(dp)):
                curr = 0
                for j in xrange(min(k-i, len(pile))+1):
                    new_dp[i+j] = max(new_dp[i+j], dp[i]+curr)
                    curr += pile[j] if j < len(pile) else 0
            dp = new_dp
        return dp[-1]
