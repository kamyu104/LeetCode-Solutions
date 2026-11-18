# Time:  O(n)
# Space: O(n)

# tree dp
class Solution(object):
    def maxScore(self, parent, op, score):
        """
        :type parent: List[int]
        :type op: List[int]
        :type score: List[int]
        :rtype: int
        """
        INF = float("inf")
        cnt = [0]*len(parent)
        for i in xrange(1, len(parent)):
            cnt[parent[i]] += 1
        dp1 = [INF]*len(parent)
        dp2 = score[:]
        for u in xrange(len(parent)):
            while cnt[u] == 0:
                if dp1[u] != INF:
                    dp2[u] -= dp1[u] if op[u] else min(dp1[u], 0)
                cnt[u] = -1
                if parent[u] == -1:
                    break
                dp1[parent[u]] = min(dp1[parent[u]], dp2[u])
                dp2[parent[u]] += dp2[u]
                cnt[parent[u]] -= 1
                u = parent[u]
        return dp2[0]
