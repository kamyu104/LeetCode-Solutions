# Time:  O(n^2)
# Space: O(n^2)

# simulation
MOD = 10**9+7
FACT, INV, INV_FACT = [[1]*2 for _ in range(3)]
def lazy_init(n):
    while len(INV) <= n:  # lazy initialization
        FACT.append(FACT[-1]*len(INV) % MOD)
        INV.append(INV[MOD%len(INV)]*(MOD-MOD//len(INV)) % MOD)  # https://cp-algorithms.com/algebra/module-inverse.html
        INV_FACT.append(INV_FACT[-1]*INV[-1] % MOD)

def factorial(n):
    lazy_init(n)
    return FACT[n]

def inv_factorial(n):
    lazy_init(n)
    return INV_FACT[n]

class Solution(object):
    def sumOfBlocks(self, n):
        """
        :type n: int
        :rtype: int
        """        
        result, left = 0, 1
        for l in xrange(n):
            right = left+l
            result = (result+(factorial(right)*inv_factorial(left-1)))%MOD
            left = right+1
        return result
