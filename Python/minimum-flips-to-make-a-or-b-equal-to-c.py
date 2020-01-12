# Time:  O(31)
# Space: O(1)

class Solution(object):
    def minFlips(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: int
        """
        result = 0
        for i in xrange(31):
            a_i, b_i, c_i = map(lambda x: x&1, [a, b, c])
            if (a_i | b_i) != c_i:
                result += 2 if a_i == b_i == 1 else 1
            a, b, c = a >> 1, b >> 1, c >> 1
        return result
