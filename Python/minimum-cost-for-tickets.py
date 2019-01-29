# Time:  O(n)
# space: O(1)

class Solution(object):
    def mincostTickets(self, days, costs):
        """
        :type days: List[int]
        :type costs: List[int]
        :rtype: int
        """
        dp = [float("inf") for i in xrange(len(days)+1)]
        dp[0] = 0
        last_buy_days = [0, 0, 0]
        durations = [1, 7, 30]
        W = durations[-1]
        for i in xrange(1,len(days)+1):
            for j in xrange(len(durations)):
                dp[i%W] = float("inf")
                while i-1 < len(days) and \
                      days[i-1] > days[last_buy_days[j]]+durations[j]-1:
                    last_buy_days[j] += 1  # Time: O(n)
                dp[i%W] = min(dp[i%W], dp[last_buy_days[j]%W]+costs[j])
        return dp[len(days)%W]
