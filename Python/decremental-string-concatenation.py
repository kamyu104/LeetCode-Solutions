# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def minimizeConcatenatedLength(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        dp = [[float("-inf")]*26 for _ in xrange(2)]
        dp[0][ord(words[0][-1])-ord('a')] = dp[1][ord(words[0][0])-ord('a')] = 0
        for i in xrange(1, len(words)):
            new_dp = [[float("-inf")]*26 for _ in xrange(2)]
            for right in xrange(2):
                for c in xrange(26):
                    if dp[right][c] == float("-inf"):
                        continue
                    l = c if right else ord(words[i-1][0])-ord('a')
                    r = c if not right else ord(words[i-1][-1])-ord('a')
                    new_dp[0][r] = max(new_dp[0][r], dp[right][c]+int(ord(words[i][-1])-ord('a') == l))
                    new_dp[1][l] = max(new_dp[1][l], dp[right][c]+int(r == ord(words[i][0])-ord('a')))
            dp = new_dp
        return sum(len(w) for w in words)-max(dp[right][c] for right in xrange(2) for c in xrange(26))
