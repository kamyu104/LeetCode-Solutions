# Time:  O((n + l) * logc)
# Space: O(n + l + logc)

# greedy, dp
class Solution(object):
    def minimumFinishTime(self, tires, changeTime, numLaps):
        """
        :type tires: List[List[int]]
        :type changeTime: int
        :type numLaps: int
        :rtype: int
        """
        def ceil_log2(x):
            return (x-1).bit_length()

        dp = [float("inf")]*ceil_log2(changeTime+1)  # dp[i]: min time to complete i+1 laps without changing a tire
        for f, r in tires:
            total = curr = f
            cnt = 0
            while curr < changeTime+f:  # at worst (f, r) = (1, 2) => 2^(cnt-1) < changeTime+1 => cnt < ceil(log2(changeTime+1))
                dp[cnt] = min(dp[cnt], total)
                curr *= r
                total += curr
                cnt += 1
        dp2 = [float("inf")]*numLaps  # dp2[i]: min time to complete i+1 laps with changing zero or more tires
        for i in xrange(numLaps):
            dp2[i] = min((dp2[i-j-1]+changeTime if i-j-1 >= 0 else 0)+dp[j] for j in xrange(min(i+1, len(dp))))
        return dp2[-1]
