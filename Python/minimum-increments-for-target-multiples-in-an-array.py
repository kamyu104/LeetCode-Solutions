# Time:  O(logr * m * 2^m + n * 3^m)
# Space: O(2^m)

# bitmasks, number theory, dp, submask enumeration
class Solution(object):
    def minimumIncrements(self, nums, target):
        """
        :type nums: List[int]
        :type target: List[int]
        :rtype: int
        """
        INF = float("inf")
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        def lcm(a, b):
            return a//gcd(a, b)*b

        n = len(nums)
        m = len(target)
        lcms = [0]*(1<<m)
        for mask in xrange(1<<m):
            l = 1
            for i in xrange(m):
                if mask&(1<<i):
                    l = lcm(l, target[i])
            lcms[mask] = l
        dp = [INF]*(1<<m)
        dp[0] = 0
        for x in nums:
            for mask in reversed(xrange(1<<m)):
                if dp[mask] == INF:
                    continue
                # submask enumeration:
                # => sum(nCr(n, k) * 2^k for k in xrange(n+1)) = (1 + 2)^n = 3^n
                # => Time: O(3^n), see https://cp-algorithms.com/algebra/all-submasks.html
                submask = new_mask = (((1<<m)-1)-mask)
                while submask:
                    dp[mask|submask] = min(dp[mask|submask], dp[mask]+(lcms[submask]-x%lcms[submask] if x%lcms[submask] else 0))
                    submask = (submask-1)&new_mask
        return dp[-1]
