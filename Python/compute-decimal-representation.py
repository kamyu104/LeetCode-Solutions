# Time:  O(logn)
# Space: O(1)

# math
class Solution(object):
    def decimalRepresentation(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        result = []
        base = 1
        while n:
            n, r = divmod(n, 10)
            if r:
                result.append(r*base)
            base *= 10
        result.reverse()
        return result
