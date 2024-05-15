# Time:  O(m * 2^m)
# Space: O(2^m)

# bitmasks, knapsack dp
class Solution(object):
    def maxHammingDistances(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: List[int]
        """
        dp = [float("-inf")]*(1<<m)
        for x in nums:
            dp[x] = 0
        for i in xrange(m):
            new_dp = dp[:]
            for mask in xrange(1<<m):
                new_dp[mask] = max(new_dp[mask], dp[mask^(1<<i)]+1)
            dp = new_dp
        return [dp[x] for x in nums]


# Time:  O(m * 2^m)
# Space: O(2^m)
# bitmasks, bfs
class Solution2(object):
    def maxHammingDistances(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: List[int]
        """
        q = []
        dist = [-1]*(1<<m)
        for x in nums:
            if dist[x] != -1:
                continue
            dist[x] = 0
            q.append(x)
        d = 0
        while q:
            d += 1
            new_q = []
            for u in q:
                for i in xrange(m):
                    if dist[u^(1<<i)] != -1:
                        continue
                    dist[u^(1<<i)] = d
                    new_q.append(u^(1<<i))
            q = new_q
        return [m-dist[((1<<m)-1)^x] for x in nums]
