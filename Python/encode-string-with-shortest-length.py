# Time:  O(n^3) on average
# Space: O(n^2)

class Solution(object):
    def encode(self, s):
        """
        :type s: str
        :rtype: str
        """
        def encode_substr(dp, s, i, j):
            temp = s[i:j+1]
            pos = (temp + temp).find(temp, 1)  # O(n) on average
            if pos >= len(temp):
                return temp
            return str(len(temp)/pos) + '[' + dp[i][i + pos - 1] + ']'

        dp = [["" for _ in xrange(len(s))] for _ in xrange(len(s))]
        for length in xrange(1, len(s)+1):
            for i in xrange(len(s)+1-length):
                j = i+length-1
                dp[i][j] = s[i:i+length]
                for k in xrange(i, j):
                    if len(dp[i][k]) + len(dp[k+1][j]) < len(dp[i][j]):
                        dp[i][j] = dp[i][k] + dp[k+1][j]
                encoded_string = encode_substr(dp, s, i, j)
                if len(encoded_string) < len(dp[i][j]):
                    dp[i][j] = encoded_string
        return dp[0][len(s) - 1]

