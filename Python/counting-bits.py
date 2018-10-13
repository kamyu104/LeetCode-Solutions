# Time:  O(n)
# Space: O(n)

class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        res = [0]
        for i in xrange(1, num + 1):
            # Number of 1's in i = (i & 1) + number of 1's in (i / 2).
            res.append((i & 1) + res[i >> 1])
        return res

    def countBits2(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        s = [0]
        while len(s) <= num:
            s.extend(map(lambda x: x + 1, s))
        return s[:num + 1]


