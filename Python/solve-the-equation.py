# Time:  O(n)
# Space: O(n)

import re


class Solution(object):
    def solveEquation(self, equation):
        """
        :type equation: str
        :rtype: str
        """
        a, b, side = 0, 0, 1
        for eq, sign, num, isx in re.findall('(=)|([-+]?)(\d*)(x?)', equation):
            if eq:
                side = -1
            elif isx:
                a += side * int(sign + '1') * int(num or 1)
            elif num:
                b -= side * int(sign + num)
        return 'x=%d' % (b / a) if a else 'No solution' if b else 'Infinite solutions'

