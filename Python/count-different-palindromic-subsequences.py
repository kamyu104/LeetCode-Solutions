# Time:  O(n^2)
# Space: O(n)

class Solution(object):
    def countPalindromicSubsequences(self, S):
        """
        :type S: str
        :rtype: int
        """
        def dp(i, j, prv, nxt, lookup):
            if lookup[i][j] is not None:
                return lookup[i][j]
            result = 1
            if i <= j:
                for x in xrange(4):
                    i0 = nxt[i][x]
                    j0 = prv[j][x]
                    if i <= i0 <= j:
                        result += 1
                    if None < i0 < j0:
                        result += dp(i0+1, j0-1, prv, nxt, lookup)
            result %= P
            lookup[i][j] = result
            return result
        
        n = len(S)
        prv = [None] * n
        nxt = [None] * n
        last = [None] * 4
        for i in xrange(len(S)):
            last[ord(S[i])-ord('a')] = i
            prv[i] = tuple(last)
            
        last = [None] * 4
        for i in reversed(xrange(len(S))):
            last[ord(S[i])-ord('a')] = i
            nxt[i] = tuple(last)
        
        P = 10**9 + 7
        lookup = [[None] * n for _ in xrange(n)]        
        return dp(0, n-1, prv, nxt, lookup) - 1
