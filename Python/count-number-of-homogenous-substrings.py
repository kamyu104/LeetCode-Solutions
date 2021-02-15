# Time:  O(n)
# Space: O(1)

class Solution(object):
    def countHomogenous(self, s):
        """
        :type s: str
        :rtype: int
        """
        MOD = 10**9+7
        result = cnt = 0
        for i in xrange(len(s)):
            if i and s[i-1] == s[i]:
                cnt += 1
            else:
                cnt = 1
            result = (result+cnt)%MOD
        return result
