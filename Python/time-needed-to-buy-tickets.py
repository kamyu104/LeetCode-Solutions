# Time:  O(n)
# Space: O(1)

class Solution(object):
    def timeRequiredToBuy(self, tickets, k):
        """
        :type tickets: List[int]
        :type k: int
        :rtype: int
        """
        return sum(min(x, tickets[k] if i <= k else tickets[k]-1) for i, x in enumerate(tickets))
