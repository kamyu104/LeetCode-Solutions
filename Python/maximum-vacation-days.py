# Time:  O(n^2 * k)
# Space: O(k)

class Solution(object):
    def maxVacationDays(self, flights, days):
        """
        :type flights: List[List[int]]
        :type days: List[List[int]]
        :rtype: int
        """
        if not days or not flights:
            return 0
        dp = [[0] * len(days) for _ in xrange(2)]
        for week in reversed(xrange(len(days[0]))):
            for cur_city in xrange(len(days)):
                dp[week % 2][cur_city] = days[cur_city][week] + dp[(week+1) % 2][cur_city]
                for dest_city in xrange(len(days)):
                    if flights[cur_city][dest_city] == 1:
                        dp[week % 2][cur_city] = max(dp[week % 2][cur_city], \
                                                     days[dest_city][week] + dp[(week+1) % 2][dest_city])
        return dp[0][0]
