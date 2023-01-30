# Time:  O(nlogn)
# Space: O(n)

# greedy, sort
class Solution(object):
    def maxPrice(self, items, capacity):
        """
        :type items: List[List[int]]
        :type capacity: int
        :rtype: float
        """
        result = 0
        for p, c in sorted(items, key=lambda x: float(x[0])/x[1], reverse=True):
            cnt = min(c, capacity)
            capacity -= cnt
            result += (float(p)/c)*cnt
        return result if capacity == 0 else -1
