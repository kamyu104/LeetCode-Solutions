# Time:  O(n^2)
# Space: O(n)

class Solution(object):
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """

        class UnionFind(object):
            def __init__(self, n):
                self.set = range(n)
                self.count = n

            def find_set(self, x):
               if self.set[x] != x:
                   self.set[x] = self.find_set(self.set[x])  # path compression.
               return self.set[x]

            def union_set(self, x, y):
                x_root, y_root = map(self.find_set, (x, y))
                if x_root != y_root:
                    self.set[min(x_root, y_root)] = max(x_root, y_root)
                    self.count -= 1

        circles = UnionFind(len(M))
        for i in xrange(len(M)):
            for j in xrange(len(M)):
                if M[i][j] and i != j:
                    circles.union_set(i, j)
        return circles.count


