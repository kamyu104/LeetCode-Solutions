# Time:  O(r * c)
# Space: O(1)


class Solution(object):
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        result = [[None] * len(A) for _ in xrange(len(A[0]))]
        for r, row in enumerate(A):
            for c, val in enumerate(row):
                result[c][r] = val
        return result


# Time:  O(r * c)
# Space: O(1)
class Solution2(object):
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        return zip(*A)

