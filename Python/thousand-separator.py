# Time:  O(n)
# Space: O(1)

class Solution(object):
    def thousandSeparator(self, n):
        """
        :type n: int
        :rtype: str
        """
        result = []
        s = str(n)
        for i, c in enumerate(str(n)):
            if i and (len(s)-i)%3 == 0:
                result.append(".")
            result.append(c)
        return "".join(result)
