# Time:  O(logn)
# Space: O(logn)

# greedy
class Solution(object):
    def smallestNumber(self, n):
        """
        :type n: int
        :rtype: str
        """
        result = []
        for d in reversed(xrange(2, 9+1)):
            while n%d == 0:
                result.append(d)
                n //= d
        return "".join(map(str, reversed(result))) or "1" if n == 1 else "-1"
