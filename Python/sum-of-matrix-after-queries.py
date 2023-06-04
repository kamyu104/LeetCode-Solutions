# Time:  O(n + q)
# Space: O(n)

# hash table
class Solution(object):
    def matrixSumQueries(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: int
        """
        lookup = [[False]*n for _ in xrange(2)]
        cnt = [0]*2
        result = 0
        for t, i, v in reversed(queries):
            if lookup[t][i]:
                continue
            lookup[t][i] = True
            cnt[t] += 1
            result += v*(n-cnt[t^1])
        return result
