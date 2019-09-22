# Time:  O(m * n)
# Space: O(n)

class Solution(object):
    def smallestCommonElement(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        # values could be duplicated in each row
        intersections = set(mat[0])
        for i in xrange(1, len(mat)):
            intersections &= set(mat[i])
            if not intersections:
                return -1
        return min(intersections)


# Time:  O(m * n)
# Space: O(n)
import collections


class Solution2(object):
    def smallestCommonElement(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        # assumed value is unique in each row
        counter = collections.Counter()
        for row in mat:
            for c in row:
                counter[c] += 1
                if counter[c] == len(mat):
                    return c
        return -1
