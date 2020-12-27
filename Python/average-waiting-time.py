# Time:  O(n)
# Space: O(1)

class Solution(object):
    def averageWaitingTime(self, customers):
        """
        :type customers: List[List[int]]
        :rtype: float
        """
        avai = wait = 0.0
        for a, t in customers:
            avai = max(avai, a)+t
            wait += avai-a
        return wait/len(customers)
