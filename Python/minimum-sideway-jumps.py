# Time:  O(n)
# Space: O(1)

class Solution(object):
    def minSideJumps(self, obstacles):
        """
        :type obstacles: List[int]
        :rtype: int
        """
        dp = [1, 0, 1]        
        for i in obstacles:
            if i:
                dp[i-1] = float("inf")
            for j in xrange(3):
                if j+1 != i:
                    dp[j] = min(dp[0]+(j != 0), dp[1]+(j != 1), dp[2]+(j != 2))
        return min(dp)
