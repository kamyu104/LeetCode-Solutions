# Time:  O(nlogn)
# Space: O(n)

# bit, fenwick tree, combinatorics
class Solution(object):
    def getPermutationIndex(self, perm):
        """
        :type perm: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        class BIT(object):  # 0-indexed.
            def __init__(self, n):
                self.__bit = [0]*(n+1)  # Extra one for dummy node.

            def add(self, i, val):
                i += 1  # Extra one for dummy node.
                while i < len(self.__bit):
                    self.__bit[i] = (self.__bit[i]+val) % MOD
                    i += (i & -i)

            def query(self, i):
                i += 1  # Extra one for dummy node.
                ret = 0
                while i > 0:
                    ret = (ret+self.__bit[i]) % MOD
                    i -= (i & -i)
                return ret

        fact = [0]*len(perm)
        fact[0] = 1
        for i in xrange(len(fact)-1):
            fact[i+1] = ((i+1)*fact[i])%MOD
        result = 0
        bit = BIT(len(perm))
        for i, x in enumerate(perm):
            result = (result+(((((x-1)-bit.query((x-1)-1))%MOD)*fact[(len(perm)-1)-i])%MOD))%MOD
            bit.add(x-1, +1)
        return result


# Time:  O(nlogn)
# Space: O(n)
# bit, fenwick tree, combinatorics
class Solution2(object):
    def getPermutationIndex(self, perm):
        """
        :type perm: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        fact = [1]*2            
        def factorial(n):
            while len(fact) <= n:  # lazy initialization
                fact.append(fact[-1]*len(fact) % MOD)
            return fact[n]

        class BIT(object):  # 0-indexed.
            def __init__(self, n):
                self.__bit = [0]*(n+1)  # Extra one for dummy node.

            def add(self, i, val):
                i += 1  # Extra one for dummy node.
                while i < len(self.__bit):
                    self.__bit[i] = (self.__bit[i]+val) % MOD
                    i += (i & -i)

            def query(self, i):
                i += 1  # Extra one for dummy node.
                ret = 0
                while i > 0:
                    ret = (ret+self.__bit[i]) % MOD
                    i -= (i & -i)
                return ret

        result = 0
        bit = BIT(len(perm))
        for i, x in enumerate(perm):
            result = (result+(((((x-1)-bit.query((x-1)-1))%MOD)*factorial((len(perm)-1)-i))%MOD))%MOD
            bit.add(x-1, +1)
        return result
