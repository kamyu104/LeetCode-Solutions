# Time:  O((n + e) * 2^n)
# Space: O(n + e)

# bitmask, dfs
class Solution(object):
    def evenSumSubgraphs(self, nums, edges):
        """
        :type nums: List[int]
        :type edges: List[List[int]]
        :rtype: int
        """
        def even(mask):
            def popcount(x):
                return bin(x).count('1')

            return not popcount(mask&odd_mask)%2
    
        def connected(mask):
            i = next(i for i in xrange(len(nums)) if mask&(1<<i))
            mask ^= 1<<i
            stk = [i]
            while stk:
                u = stk.pop()
                for v in adj[u]:
                    if not mask&(1<<v):
                        continue
                    mask ^= 1<<v
                    stk.append(v)
            return not mask

        adj = [[] for _ in xrange(len(nums))]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        odd_mask = reduce(lambda accu, x: accu|(1<<x), (i for i in xrange(len(nums)) if nums[i]), 0)
        return sum(even(mask) and connected(mask) for mask in xrange(1, 1<<len(nums)))


# Time:  O((n + e) * 2^n)
# Space: O(n + e)
# bitmask, dfs
class Solution2(object):
    def evenSumSubgraphs(self, nums, edges):
        """
        :type nums: List[int]
        :type edges: List[List[int]]
        :rtype: int
        """
        def even(mask):
            parity = 0
            for i in xrange(len(nums)):
                if not mask&(1<<i):
                    continue
                parity ^= nums[i]
            return not parity
    
        def connected(mask):
            i = next(i for i in xrange(len(nums)) if mask&(1<<i))
            mask ^= 1<<i
            stk = [i]
            while stk:
                u = stk.pop()
                for v in adj[u]:
                    if not mask&(1<<v):
                        continue
                    mask ^= 1<<v
                    stk.append(v)
            return not mask

        adj = [[] for _ in xrange(len(nums))]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        return sum(even(mask) and connected(mask) for mask in xrange(1, 1<<len(nums)))
