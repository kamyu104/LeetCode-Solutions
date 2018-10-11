# Time:  O(n)
# Space: O(1)

class Solution(object):
    def decodeAtIndex(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        i = 0
        for c in S:
            if c.isdigit():
                i *= int(c)
            else:
                i += 1

        for c in reversed(S):
            K %= i
            if K == 0 and c.isalpha():
                return c

            if c.isdigit():
                i /= int(c)
            else:
                i -= 1

