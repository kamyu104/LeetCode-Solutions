# Time:  O(n * k^2)
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
            for j in xrange(len(dp)):
                curr = 0
                for l in xrange(min(k-j, len(pile))+1):
                    new_dp[j+l] = max(new_dp[j+l], dp[j]+curr)
                    curr += pile[l] if l < len(pile) else 0
            dp = new_dp
        return dp[-1]
