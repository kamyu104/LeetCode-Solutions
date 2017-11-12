# Time:  O(S * T)
# Space: O(S)

class Solution(object):
    def minWindow(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: str
        """
        dp = [[None for _ in xrange(len(S))] for _ in xrange(2)]
        for j, c in enumerate(S):
            if c == T[0]:
                dp[0][j] = j
                
        for i in xrange(1, len(T)):
            prev = None
            dp[i%2] = [None] * len(S)
            for j, c in enumerate(S):
                if prev is not None and c == T[i]:
                    dp[i%2][j] = prev
                if dp[(i-1)%2][j] is not None:
                    prev = dp[(i-1)%2][j]

        start, end = 0, len(S)
        for j, i in enumerate(dp[(len(T)-1)%2]):
            if i >= 0 and j-i < end-start:
                start, end = i, j
        return S[start:end+1] if end < len(S) else ""
