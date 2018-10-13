# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        result, dvd = "", n

        while dvd:
            result += chr((dvd - 1) % 26 + ord('A'))
            dvd = (dvd - 1) / 26

        return result[::-1]


