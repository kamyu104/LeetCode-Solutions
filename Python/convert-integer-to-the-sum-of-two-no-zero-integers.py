# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def getNoZeroIntegers(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        a, curr, base = 0, n, 1
        while curr: 
            if curr % 10 == 0 or (curr % 10 == 1 and curr != 1):
                a += base
                curr -= 10  # carry
            a += base
            base *= 10
            curr //= 10
        return [a, n-a]


# Time:  O(nlogn)
# Space: O(logn)
class Solution2(object):
    def getNoZeroIntegers(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        return next([a, n-a] for a in xrange(1, n) if '0' not in '{}{}'.format(a, n-a))
