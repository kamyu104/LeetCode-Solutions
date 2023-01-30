# Time:  O(logn)
# Space: O(1)

# combinatorics, fast exponentiation
class Solution(object):
    def monkeyMove(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
        return (pow(2, n, MOD)-2)%MOD
