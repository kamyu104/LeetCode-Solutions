# Time:  O(n)
# Space: O(1)

class Solution(object):
    def minOperationsMaxProfit(self, customers, boardingCost, runningCost):
        """
        :type customers: List[int]
        :type boardingCost: int
        :type runningCost: int
        :rtype: int
        """
        max_run = -1
        i = max_prof = prof = waiting = 0
        run = 1
        while i < len(customers) or waiting > 0:
            if i < len(customers):
                waiting += customers[i]  # each run i increases people by customers[i]
                i += 1
            boarding = min(waiting, 4)  # greedy
            waiting -= boarding
            prof += boarding * boardingCost - runningCost 
            if prof > max_prof:
                max_prof = prof
                max_run = run
            run += 1
        return max_run
