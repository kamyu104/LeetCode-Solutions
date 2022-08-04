# Time:  O(n)
# Space: O(n)

# graph
class Solution(object):
    def longestCycle(self, edges):
        """
        :type edges: List[int]
        :rtype: int
        """
        result = -1
        lookup = [-1]*len(edges)
        idx = 0
        for i in xrange(len(edges)):
            if lookup[i] != -1:
                continue
            start = idx
            while i != -1:
                if lookup[i] != -1:
                    break
                lookup[i] = idx
                idx += 1
                i = edges[i]
            if i != -1 and lookup[i] >= start:
                result = max(result, idx-lookup[i])
        return result
