# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        result = []
        while n:
            result += chr((n-1)%26 + ord('A'))
            n = (n-1)//26
        result.reverse()
        return "".join(result)

