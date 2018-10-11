# Time:  O(1)
# Space: O(1)

class Solution(object):
    def soupServings(self, N):
        """
        :type N: int
        :rtype: float
        """
        def dp(a, b, lookup):
            if (a, b) in lookup:
                return lookup[a, b]
            if a <= 0 and b <= 0:
                return 0.5
            if a <= 0:
                return 1.0
            if b <= 0:
                return 0.0
            lookup[a, b] = 0.25 * (dp(a-4, b, lookup) +
                                   dp(a-3, b-1, lookup) +
                                   dp(a-2, b-2, lookup) +
                                   dp(a-1, b-3, lookup))
            return lookup[a, b]

        if N >= 4800:
            return 1.0
        lookup = {}
        N = (N+24)//25
        return dp(N, N, lookup)

