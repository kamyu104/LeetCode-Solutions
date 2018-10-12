# Time:  O(nlogx), x is the max denominator
# Space: O(n)

import re


class Solution(object):
    def fractionAddition(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        ints = map(int, re.findall('[+-]?\d+', expression))
        A, B = 0, 1
        for i in xrange(0, len(ints), 2):
            a, b = ints[i], ints[i+1]
            A = A * b + a * B
            B *= b
            g = gcd(A, B)
            A //= g
            B //= g
        return '%d/%d' % (A, B)

