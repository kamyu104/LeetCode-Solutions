# Time:  O(sqrt(n))
# Space: O(1)

# greedy
class Solution(object):
    def maximumEvenSplit(self, finalSum):
        """
        :type finalSum: int
        :rtype: List[int]
        """
        if finalSum%2:
            return []
        result = []
        i = 2
        while i <= finalSum:
            result.append(i)
            finalSum -= i
            i += 2
        result[-1] += finalSum
        return result
