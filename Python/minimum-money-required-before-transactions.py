# Time:  O(n)
# Space: O(1)

# greedy, constructive algorithms
class Solution(object):
    def minimumMoney(self, transactions):
        """
        :type transactions: List[List[int]]
        :rtype: int
        """
        return sum(max(a-b, 0) for a, b in transactions)+max(a-max(a-b, 0) for a, b in transactions)  # a-max(a-b, 0) = min(a, b)
