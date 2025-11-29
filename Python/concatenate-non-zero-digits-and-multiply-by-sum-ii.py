# Time:  O(n)
# Space: O(n)

# prefix sum
class Solution(object):
    def sumAndMultiply(self, s, queries):
        """
        :type s: str
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        MOD = 10**9+7
        pow10 = [0]*(len(s)+1)
        pow10[0] = 1
        idx = [0]*(len(s)+1)
        x = [0]*(len(s)+1)
        total = [0]*(len(s)+1)
        for i in xrange(len(s)):
            d = ord(s[i])-ord('0')
            pow10[i+1] = (pow10[i]*10)%MOD
            idx[i+1] = idx[i]+(1 if d else 0)
            x[i+1] = (x[i]*10+d) % MOD if d else x[i]
            total[i+1] = total[i]+d
        return [(((x[r+1]-x[l]*pow10[idx[r+1]-idx[l]])%MOD)*(total[r+1]-total[l]))%MOD for l, r in queries]
