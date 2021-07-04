# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def countGoodNumbers(self, n):
        """
        :type n: int
        :rtype: int
        """
        def powmod(a, b, mod):
            a %= mod
            result = 1
            while b:
                if b&1:
                    result = (result*a)%mod
                a = (a*a)%mod
                b >>= 1
            return result

        MOD = 10**9 + 7
        return powmod(5, (n+1)//2%(MOD-1), MOD)*powmod(4, n//2%(MOD-1), MOD) % MOD


# Time:  O(logn)
# Space: O(1)
class Solution2(object):
    def countGoodNumbers(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9 + 7
        return pow(5, (n+1)//2%(MOD-1), MOD)*pow(4, n//2%(MOD-1), MOD) % MOD
