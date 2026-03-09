# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def minimumIndex(self, capacity, itemSize):
        """
        :type capacity: List[int]
        :type itemSize: int
        :rtype: int
        """
        result = (float("inf"), -1)
        for i, x in enumerate(capacity):
            if x >= itemSize:
                result = min(result, (x, i))
        return result[1]
