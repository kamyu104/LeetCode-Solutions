# Time:  O(m * n)
# Space: O(m)

class Solution(object):
    def findGoodStrings(self, n, s1, s2, evil):
        """
        :type n: int
        :type s1: str
        :type s2: str
        :type evil: str
        :rtype: int
        """
        MOD = 10**9+7
        def getPrefix(pattern):
            prefix = [-1]*len(pattern)
            j = -1
            for i in xrange(1, len(pattern)):
                while j != -1 and pattern[j+1] != pattern[i]:
                    j = prefix[j]
                if pattern[j+1] == pattern[i]:
                    j += 1
                prefix[i] = j
            return prefix
    
        prefix = getPrefix(evil)
        dp = [[[[0]*len(evil) for _ in xrange(2)] for _ in xrange(2)] for _ in xrange(2)]
        dp[0][0][0][0] = 1
        for i in xrange(n):
            dp[(i+1)%2] = [[[0]*len(evil) for _ in xrange(2)] for _ in xrange(2)]
            for j in xrange(2):
                for k in xrange(2):
                    min_c = 'a' if j else s1[i]
                    max_c = 'z' if k else s2[i]
                    for l in xrange(len(evil)):
                        if not dp[i%2][j][k][l]:
                            continue
                        for c in xrange(ord(min_c)-ord('a'), ord(max_c)-ord('a')+1):
                            c = chr(c+ord('a'))
                            m = l-1
                            while m != -1 and evil[m+1] != c:
                                m = prefix[m]
                            if evil[m+1] == c:
                                m += 1
                            if m+1 == len(evil):
                                continue
                            dp[(i+1)%2][j or (s1[i] != c)][k or (s2[i] != c)][m+1] = \
                                (dp[(i+1)%2][j or (s1[i] != c)][k or (s2[i] != c)][m+1] + dp[i%2][j][k][l]) % MOD
        result = 0
        for j in xrange(2):
            for k in xrange(2):
                for l in xrange(len(evil)):
                    result = (result + dp[n%2][j][k][l]) % MOD
        return result
