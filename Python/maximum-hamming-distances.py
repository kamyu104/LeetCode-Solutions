# Time:  O(m * 2^m)
# Space: O(2^m)

# bitmasks, bfs
class Solution(object):
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
        lookup = [False]*(1<<m)
        for x in nums:
            lookup[x] = True
        d = m
        q = nums
        while q:
            new_q = []
            for u in q:
                for v in group[u]:
                    result[v] = d
                for i in xrange(m):
                    if lookup[u^(1<<i)]:
                        continue
                    lookup[u^(1<<i)] = True
                    new_q.append(u^(1<<i))
            q = new_q
            d -= 1
        return result
    
