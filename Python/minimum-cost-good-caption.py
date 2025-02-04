# Time:  O(26 * n)
# Space: O(26 * n)

# dp, backtracing
class Solution(object):
    def minCostGoodCaption(self, caption):
        """
        :type caption: str
        :rtype: str
        """
        L = 3
        n = len(caption)
        if n < L:
            return ""
        dp = [[[0]*2 for _ in xrange(26)] for _ in xrange(n-L+1)]
        mn = [[0]*2 for _ in xrange(n-L+1)]
        cap = map(lambda x: ord(x)-ord('a'), caption)
        for i in reversed(xrange(n-L+1)):
            for j in xrange(26):
                if i == n-L:
                    dp[i][j][:] = [sum(abs(cap[k]-j) for k in xrange(i, i+L)), L]
                    continue
                dp[i][j][:] = [dp[i+1][j][0]+abs(cap[i]-j), 1]
                if i+L < n-2:
                    curr, c = mn[i+L]
                    curr += sum(abs(cap[k]-j) for k in xrange(i, i+L))
                    if curr < dp[i][j][0] or (curr == dp[i][j][0] and c < j):
                        dp[i][j][:] = [curr, L]
            mn[i] = min([dp[i][j][0], j] for j in xrange(26))
        result = []
        i, j, l = 0, mn[0][1], 1
        while i != n:
            if l == L:
                j = mn[i][1]
            l = dp[i][j][1]
            result.append(chr(ord('a')+j)*l)
            i += l
        return "".join(result)
