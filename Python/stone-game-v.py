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
        
        dp = [[0]*n for _ in xrange(n)]
        for i in xrange(n):
            dp[i][i] = stoneValue[i]
        p = range(n)
        max_score = 0
        for l in xrange(1, n):
            for i in xrange(n-l):
                j = i+l
                while prefix[p[i]+1]-prefix[i] < prefix[j+1]-prefix[p[i]+1]:
                    p[i] += 1
                max_score = 0
                if prefix[p[i]+1]-prefix[i] == prefix[j+1]-prefix[p[i]+1]:
                    max_score = max(dp[i][p[i]], dp[j][p[i]+1])
                else:
                    if i <= p[i]-1:
                        max_score = max(max_score, dp[i][p[i]-1])
                    if p[i]+1 <= j:
                        max_score = max(max_score, dp[j][p[i]+1])
                dp[i][j] = max(dp[i][j-1], (prefix[j+1]-prefix[i]) + max_score)
                dp[j][i] = max(dp[j][i+1], (prefix[j+1]-prefix[i]) + max_score)
        return max_score


# Time:  O(n^2)
# Space: O(n^2)
class Solution2(object):
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
                j = i+l-1
                p = i+1 if l == 1 else mid[i][j-1]
                while prefix[p]-prefix[i] < prefix[j+1]-prefix[p]:
                    p += 1  # Time: O(n^2) in total
                mid[i][j] = p
        
        rmq = [[0]*n for _ in xrange(n)]
        for i in xrange(n):
            rmq[i][i] = stoneValue[i]

        dp = [[0]*n for _ in xrange(n)]
        for l in xrange(2, n+1):
            for i in xrange(n-l+1):
                j = i+l-1
                p = mid[i][j]
                max_score = 0
                if prefix[p]-prefix[i] == prefix[j+1]-prefix[p]:
                    max_score = max(rmq[i][p-1], rmq[j][p])
                else:
                    if i <= p-2:
                        max_score = max(max_score, rmq[i][p-2])
                    if p <= j:
                        max_score = max(max_score, rmq[j][p])
                dp[i][j] = max_score
                rmq[i][j] = max(rmq[i][j-1], (prefix[j+1]-prefix[i]) + max_score)
                rmq[j][i] = max(rmq[j][i+1], (prefix[j+1]-prefix[i]) + max_score)
        return dp[0][n-1]
