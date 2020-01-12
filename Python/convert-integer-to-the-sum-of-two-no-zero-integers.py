# Time:  O(logn)
# Space: O(logn)

class Solution(object):
    def getNoZeroIntegers(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        curr, digits = n, []
        while curr: 
            if curr % 10 == 0 or \
               (curr % 10 == 1 and curr != 1):
                digits.append('2')
                curr -= 10  # carry
            else:
                digits.append('1')
            curr //= 10
        digits.reverse()
        a = int("".join(digits))
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
