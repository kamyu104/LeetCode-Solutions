# Time:  O(n^2)
# Space: O(n^2)

class Solution(object):
    def stoneGameV(self, stoneValue):
        """
        :type stoneValue: List[int]
        :rtype: int
        """
        n = len(stoneValue)
        prefix = [0]
        for v in stoneValue:
            prefix.append(prefix[-1] + v)

        mid = [[0]*n for _ in xrange(n)]
        for l in xrange(1, n+1):
            for i in xrange(n-l+1):
                p = i+1 if l == 1 else mid[i][i+l-2]
                while prefix[p]-prefix[i] < prefix[i+l]-prefix[p]:
                    p += 1  # Time: O(n^2) in total
                mid[i][i+l-1] = p
        
        rmq = [[0]*n for _ in xrange(n)]
        for i in xrange(n):
            rmq[i][i] = stoneValue[i]

        dp = [[0]*n for _ in xrange(n)]
        for l in xrange(2, n+1):
            for i in xrange(n-l+1):
                p = mid[i][i+l-1]
                max_score = 0
                if prefix[p]-prefix[i] == prefix[i+l]-prefix[p]:
                    max_score = max(rmq[i][p-1], rmq[p][i+l-1])
                else:
                    if i <= p-2:
                        max_score = max(max_score, rmq[i][p-2])
                    if p <= i+l-1:
                        max_score = max(max_score, rmq[i+l-1][p])
                dp[i][i+l-1] = max_score
                rmq[i][i+l-1] = max(rmq[i][i+l-2], (prefix[i+l]-prefix[i]) + max_score)
                rmq[i+l-1][i] = max(rmq[i+l-1][i+1], (prefix[i+l]-prefix[i]) + max_score)
        return dp[0][n-1]
