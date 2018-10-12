# Time:  O(m * n)
# Space: O(m + n)

class Solution(object):
    def findLonelyPixel(self, picture):
        """
        :type picture: List[List[str]]
        :rtype: int
        """
        rows, cols = [0] * len(picture),  [0] * len(picture[0])
        for i in xrange(len(picture)):
            for j in xrange(len(picture[0])):
                if picture[i][j] == 'B':
                    rows[i] += 1
                    cols[j] += 1

        result = 0
        for i in xrange(len(picture)):
            if rows[i] == 1:
                for j in xrange(len(picture[0])):
                     result += picture[i][j] == 'B' and cols[j] == 1
        return result


class Solution2(object):
    def findLonelyPixel(self, picture):
        """
        :type picture: List[List[str]]
        :type N: int
        :rtype: int
        """
        return sum(col.count('B') == 1 == picture[col.index('B')].count('B') \
               for col in zip(*picture))

