# Time:  O(logn + qlogr), r = MOD
# Space: O(logn)

# prefix sum
class Solution(object):
    def productQueries(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        MOD = 10**9+7
        prefix = [0]
        i = 0
        while (1<<i) <= n:
            if n&(1<<i):
                prefix.append(prefix[-1]+i)
            i += 1
        return [pow(2, prefix[r+1]-prefix[l], MOD) for l, r in queries]
