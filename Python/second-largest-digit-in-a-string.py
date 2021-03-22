# Time:  O(n)
# Space: O(1)

class Solution(object):
    def secondHighest(self, s):
        """
        :type s: str
        :rtype: int
        """
        first = second = -1
        for c in s:
            if not c.isdigit():
                continue
            d = int(c)
            if d > first:
                first, second = d, first
            elif first > d > second:
                second = d
        return second
