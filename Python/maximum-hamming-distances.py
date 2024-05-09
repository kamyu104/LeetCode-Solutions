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
        group = [[] for _ in xrange(1<<m)]
        for i, x in enumerate(nums):
            group[((1<<m)-1)^x].append(i)
        result = [0]*len(nums)
        q = []
        lookup = [False]*(1<<m)
        for x in nums:
            if lookup[x]:
                continue
            lookup[x] = True
            q.append(x)
        d = 0
        while q:
            new_q = []
            for u in q:
                for i in group[u]:
                    result[i] = m-d
                for i in xrange(m):
                    if lookup[u^(1<<i)]:
                        continue
                    lookup[u^(1<<i)] = True
                    new_q.append(u^(1<<i))
            q = new_q
            d += 1
        return result
