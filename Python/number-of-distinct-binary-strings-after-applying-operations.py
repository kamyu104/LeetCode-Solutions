# Time:  O(logn)
# Space: O(1)

# combinatorics
class Solution(object):
    def countDistinctStrings(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        return pow(2, len(s)-k+1, MOD)
