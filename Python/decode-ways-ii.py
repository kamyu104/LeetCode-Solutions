# Time:  O(n)
# Space: O(1)

# A message containing letters from A-Z is being encoded to numbers using the following mapping way:
#
# 'A' -> 1
# 'B' -> 2
# ...
# 'Z' -> 26
# Beyond that, now the encoded string can also contain the character '*',
# which can be treated as one of the numbers from 1 to 9.
#
# Given the encoded message containing digits and the character '*', return the total number of ways to decode it.
#
# Also, since the answer may be very large, you should return the output mod 109 + 7.
#
# Example 1:
# Input: "*"
# Output: 9
# Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
# Example 2:
# Input: "1*"
# Output: 9 + 9 = 18
# Note:
# The length of the input string will fit in range [1, 105].
# The input string will only contain the character '*' and digits '0' - '9'.

class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        M, W = 1000000007, 3
        dp = [0] * W
        dp[0] = 1
        dp[1] = 9 if s[0] == '*' else dp[0] if s[0] != '0' else 0
        for i in xrange(1, len(s)):
            if s[i] == '*':
                dp[(i + 1) % W] = 9 * dp[i % W]
                if s[i - 1] == '1':
                    dp[(i + 1) % W] = (dp[(i + 1) % W] + 9 * dp[(i - 1) % W]) % M
                elif s[i - 1] == '2':
                    dp[(i + 1) % W] = (dp[(i + 1) % W] + 6 * dp[(i - 1) % W]) % M
                elif s[i - 1] == '*':
                    dp[(i + 1) % W] = (dp[(i + 1) % W] + 15 * dp[(i - 1) % W]) % M
            else:
                dp[(i + 1) % W] = dp[i % W] if s[i] != '0' else 0
                if s[i - 1] == '1':
                    dp[(i + 1) % W] = (dp[(i + 1) % W] + dp[(i - 1) % W]) % M
                elif s[i - 1] == '2' and s[i] <= '6':
                    dp[(i + 1) % W] = (dp[(i + 1) % W] + dp[(i - 1) % W]) % M
                elif s[i - 1] == '*':
                    dp[(i + 1) % W] = (dp[(i + 1) % W] + (2 if s[i] <= '6' else 1) * dp[(i - 1) % W]) % M
        return dp[len(s) % W]
