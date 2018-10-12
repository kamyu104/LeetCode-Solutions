# Time:  O(n)
# Space: O(1)

class Solution(object):
    def isConvex(self, points):
        """
        :type points: List[List[int]]
        :rtype: bool
        """
        def det(A):
            return A[0][0]*A[1][1] - A[0][1]*A[1][0]

        n, prev, curr = len(points), 0, None
        for i in xrange(len(points)):
            A = [[points[(i+j) % n][0] - points[i][0], points[(i+j) % n][1] - points[i][1]] for j in (1, 2)]
            curr = det(A)
            if curr:
                if curr * prev < 0:
                    return False
                prev = curr
        return True


