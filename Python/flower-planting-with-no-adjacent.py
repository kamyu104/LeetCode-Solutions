# Time:  O(n)
# Space: O(n)

class Solution(object):
    def gardenNoAdj(self, N, paths):
        """
        :type N: int
        :type paths: List[List[int]]
        :rtype: List[int]
        """
        result = [0]*N
        G = [[] for i in xrange(N)]
        for x, y in paths:
            G[x-1].append(y-1)
            G[y-1].append(x-1)
        for i in xrange(N):
            result[i] = ({1, 2, 3, 4} - {result[j] for j in G[i]}).pop()
        return result
