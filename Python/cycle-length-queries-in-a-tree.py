# Time:  O(q * n)
# Space: O(1)

# tree, lca
class Solution(object):
    def cycleLengthQueries(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        result = []
        for x, y in queries:
            cnt = 1
            while x != y:
                if x > y:
                    x, y = y, x
                y //= 2
                cnt += 1
            result.append(cnt)
        return result
