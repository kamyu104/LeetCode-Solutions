# Time:  O(1)
# Space: O(1)

class Solution(object):
    def totalMoney(self, n):
        """
        :type n: int
        :rtype: int
        """
        def arithmetic_sequence_sum(a, d, n):
            return (2*a + (n-1)*d) * n //2

        cost, day = 1, 7
        first_week_cost = arithmetic_sequence_sum(cost, cost, day)
        week, remain_day = divmod(n, day)
        return arithmetic_sequence_sum(first_week_cost, cost*day, week) + \
               arithmetic_sequence_sum(cost*(week+1), cost, remain_day)
