# Time:  O(n^2)
# Space: O(n)

# dp
class Solution(object):
    def minimumBeautifulSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_pow_5 = 1
        while max_pow_5*5 <= (1<<len(s))-1:
            max_pow_5 *= 5
        dp = [float("inf")]*(len(s)+1)
        dp[0] = 0
        for i in xrange(len(s)):
            if s[i] == '0':
                continue
            curr = 0
            for j in xrange(i, len(s)):
                curr = curr*2+int(s[j])
                if max_pow_5%curr == 0:
                    dp[j+1] = min(dp[j+1], dp[(i-1)+1]+1)
        return dp[-1] if dp[-1] != float("inf") else -1


# Time:  O(n^2)
# Space: O(n)
# dp
class Solution2(object):
    def minimumBeautifulSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_pow_5 = 1
        while max_pow_5*5 <= (1<<len(s))-1:
            max_pow_5 *= 5
        dp = [float("inf")]*(len(s)+1)
        dp[0] = 0
        for i in xrange(len(s)):
            curr = 0
            for j in reversed(xrange(i+1)):
                curr += int(s[j])<<(i-j)
                if s[j] == '1' and max_pow_5%curr == 0:
                    dp[i+1] = min(dp[i+1], dp[(j-1)+1]+1)
        return dp[-1] if dp[-1] != float("inf") else -1
