# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def minMovesToCaptureTheQueen(self, a, b, c, d, e, f):
        """
        :type a: int
        :type b: int
        :type c: int
        :type d: int
        :type e: int
        :type f: int
        :rtype: int
        """
        if a == e and not (a == c and (b-d)*(f-d) < 0):
            return 1
        if b == f and not (b == d and (a-c)*(e-c) < 0):
            return 1
        if c+d == e+f and not (c+d == a+b and (c-a)*(e-a) < 0):
            return 1
        if c-d == e-f and not (c-d == a-b and (d-b)*(f-b) < 0):
            return 1
        return 2
