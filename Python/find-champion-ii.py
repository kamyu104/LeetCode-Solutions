# Time:  O(n)
# Space: O(n)

# graph, hash table
class Solution2(object):
    def findChampion(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        lookup = [False]*n
        for u, v in edges:
            lookup[v] = True
        result = -1
        for u in xrange(n):
            if lookup[u]:
                continue
            if result != -1:
                return -1
            result = u
        return result


# Time:  O(n)
# Space: O(n)
# graph, hash table
class Solution2(object):
    def findChampion(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        lookup = {v for _, v in edges}
        return next(u for u in xrange(n) if u not in lookup) if len(lookup) == n-1 else -1
