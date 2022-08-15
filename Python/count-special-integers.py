# Time:  O(logn)
# Space: O(logn)

# combinatorics
class Solution(object):
    def countSpecialNumbers(self, n):
        """
        :type n: int
        :rtype: int
        """
        def P(m, n):
            result = 1
            for _ in xrange(n):
                result *= m
                m -= 1
            return result

        digits = map(int, str(n+1))
        result = sum(P(9, 1)*P(9, i-1) for i in xrange(1, len(digits)))
        lookup = set()
        for i, x in enumerate(digits):
            for y in xrange(int(i == 0), x):
                if y in lookup:
                    continue
                result += P(9-i, len(digits)-i-1)
            if x in lookup:
                break
            lookup.add(x)
        return result
