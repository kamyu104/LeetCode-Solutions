# Time:  O(n^2)
# Space: O(1)

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3

class Solution(object):
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        for row in A:
            for i in xrange((len(row)+1) // 2):
                row[i], row[~i] = row[~i] ^ 1, row[i] ^ 1
        return A

