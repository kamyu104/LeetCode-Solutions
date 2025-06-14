# Time:  O(n^2)
# Space: O(26^2)

import collections


# dp, greedy
class Solution(object):
    def minOperations(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        n = len(word1)
        dp = [[0]*n for _ in xrange(n)]
        for i in xrange(2*n-1):
            cnt = collections.defaultdict(int)
            curr = 1  # 1 for reversing
            left, right = i//2, (i+1)//2
            while 0 <= left and right < n:
                for j in xrange(2):
                    x, y = word1[left], word2[right]
                    if x != y and (left != right or j == 0):
                        if cnt[y, x]:
                            cnt[y, x] -= 1
                        else:
                            cnt[x, y] += 1
                            curr += 1
                    right, left = left, right
                dp[left][right] = curr
                left -= 1
                right += 1
        dp2 = [float("inf")]*(n+1)
        dp2[0] = 0
        for i in xrange(n):
            cnt = collections.defaultdict(int)
            curr = 0
            for j in reversed(xrange(i+1)):
                x, y = word1[j], word2[j]
                if x != y:
                    if cnt[y, x]:
                        cnt[y, x] -= 1
                    else:
                        cnt[x, y] += 1
                        curr += 1
                dp2[i+1] = min(dp2[i+1], dp2[j]+min(curr, dp[j][i]))
        return dp2[n]
