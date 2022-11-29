# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def bestClosingTime(self, customers):
        """
        :type customers: str
        :rtype: int
        """
        result = mx = curr = 0
        for i, x in enumerate(customers):
            curr += 1 if x == 'Y' else -1
            if curr > mx:
                mx = curr
                result = i+1
        return result
