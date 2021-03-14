# Time:  O(1)
# Space: O(1)

class Solution(object):
    def findCenter(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: int
        """
        return edges[0][edges[0][1] in edges[1]]
