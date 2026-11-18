# Time:  O(log(n + k))
# Space: O(1)

# bitmasks, combinatorics
class Solution(object):
    def sumOfGoodIntegers(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        def popcount(x):
            return bin(x).count('1')

        def count(x):
            l = x.bit_length()
            mask = ((1<<l)-1)&~n
            c = popcount(mask)
            result = prefix = 0
            for i in reversed(xrange(l)):
                if mask&(1<<i):
                    mask ^= 1<<i
                    c -= 1
                if x&(1<<i) == 0:
                    continue
                result = (result+(prefix<<c)+((mask<<c)>>1))%MOD
                if n&(1<<i):
                    return result
                prefix |= 1<<i
            result = (result+x)%MOD
            return result
    
        return (count(n+k)-count(max(n-k, 1)-1))%MOD
