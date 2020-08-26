# Time:  O(e)
# Space: O(n)

class Solution(object):
    def findSmallestSetOfVertices(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        result = []
        lookup = set()
        for u, v in edges:
            lookup.add(v)
        for i in xrange(n):
            if i not in lookup:
                result.append(i)
        return result
