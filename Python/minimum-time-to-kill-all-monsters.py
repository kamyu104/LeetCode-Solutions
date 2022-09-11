# Time:  O(n * 2^n)
# Space: O(2^n)

# bitmasks, dp
class Solution(object):
    def minimumTime(self, power):
        """
        :type power: List[int]
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b

        INF = float("inf")
        dp = {0:0}
        for gain in xrange(1, len(power)+1):
            new_dp = collections.defaultdict(lambda:INF)
            for mask in dp.iterkeys():
                for i in xrange(len(power)):
                    if mask&(1<<i) == 0:
                        new_dp[mask|(1<<i)] = min(new_dp[mask|(1<<i)], dp[mask]+ceil_divide(power[i], gain))
            dp = new_dp
        return dp[(1<<len(power))-1]
