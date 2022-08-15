# Time:  O(n)
# Space: O(n)

# freq table
class Solution(object):
    def edgeScore(self, edges):
        """
        :type edges: List[int]
        :rtype: int
        """
        score = [0]*len(edges)
        for u, v in enumerate(edges):
            score[v] += u
        return max(xrange(len(edges)), key=lambda x:score[x])
    
