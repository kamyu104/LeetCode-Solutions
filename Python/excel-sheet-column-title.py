from __future__ import print_function
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

if __name__ == "__main__":
    for i in xrange(1, 29):
        print(Solution().convertToTitle(i))

