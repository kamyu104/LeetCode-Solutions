# Time:  O(k * 3^n)
# Space: O(2^n)

# dp, submask enumeration
class Solution(object):
    def distributeCookies(self, cookies, k):
        """
        :type cookies: List[int]
        :type k: int
        :rtype: int
        """
        total = [0]*(1<<len(cookies))
        for mask in xrange(1<<len(cookies)):
            total[mask] = sum(cookies[i] for i in xrange(len(cookies)) if mask&(1<<i))
        dp = [[float("inf")]*(1<<len(cookies)) for _ in xrange(2)]
        dp[0][0] = 0
        for i in xrange(k):
            for mask in xrange(1<<len(cookies)):
                submask = mask
                while submask:
                    dp[(i+1)%2][mask] = min(dp[(i+1)%2][mask], max(total[submask], dp[i%2][mask^submask]))
                    submask = (submask-1)&mask
        return dp[k%2][-1]
