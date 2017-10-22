# Time:  O(m * n)
# Space: O(n)

# Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.
#
# Example 1:
# Input: s1 = "sea", s2 = "eat"
# Output: 231
# Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
# Deleting "t" from "eat" adds 116 to the sum.
# At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
#
# Example 2:
# Input: s1 = "delete", s2 = "leet"
# Output: 403
# Explanation: Deleting "dee" from "delete" to turn the string into "let",
# adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
# At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
# If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
#
# Note:
# - 0 < s1.length, s2.length <= 1000.
# - All elements of each string will have an ASCII value in [97, 122].

# DP with rolling window
class Solution(object):
    def minimumDeleteSum(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        dp = [[0] * (len(s2)+1) for _ in xrange(2)]
        for j in xrange(len(s2)):
            dp[0][j+1] = dp[0][j] + ord(s2[j])

        for i in xrange(len(s1)):
            dp[(i+1)%2][0] = dp[i%2][0] + ord(s1[i])
            for j in xrange(len(s2)):
                if s1[i] == s2[j]:
                    dp[(i+1)%2][j+1] = dp[i%2][j]
                else:
                    dp[(i+1)%2][j+1] = min(dp[i%2][j+1] + ord(s1[i]),
                                           dp[(i+1)%2][j] + ord(s2[j]))

        return dp[len(s1)%2][-1]


# Time:  O(m * n)
# Space: O(m * n)
class Solution2(object):
    def minimumDeleteSum(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        
        dp = [[0] * (len(s2)+1) for _ in xrange(len(s1)+1)]

        for i in xrange(len(s1)):
            dp[i+1][0] = dp[i][0] + ord(s1[i])
        for j in xrange(len(s2)):
            dp[0][j+1] = dp[0][j] + ord(s2[j])

        for i in xrange(len(s1)):
            for j in xrange(len(s2)):
                if s1[i] == s2[j]:
                    dp[i+1][j+1] = dp[i][j]
                else:
                    dp[i+1][j+1] = min(dp[i][j+1] + ord(s1[i]),
                                       dp[i+1][j] + ord(s2[j]))

        return dp[-1][-1]
