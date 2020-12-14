# Time:  O(n^2)
# Space: O(n^2)

class Solution(object):
    def stoneGameVII(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        def score(i, j):
            return prefix[j+1]-prefix[i]

        prefix = [0]
        for stone in stones:
            prefix.append(prefix[-1]+stone)
        dp = [[0 for _ in xrange(len(stones))] for _ in xrange(len(stones))]
        for i in reversed(xrange(len(stones))):
            for j in xrange(i+1, len(stones)):
                dp[i][j] = max(score(i+1, j)-dp[i+1][j], score(i, j-1)-dp[i][j-1])
        return dp[0][-1]
