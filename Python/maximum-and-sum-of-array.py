# Time:  O(n^3)
# Space: O(n^2)

# weighted bipartite matching solution
class Solution(object):
    def maximumANDSum(self, nums, numSlots):
        """
        :type nums: List[int]
        :type numSlots: int
        :rtype: int
        """
        # Template translated from:
        # https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/WeightedMatching.h
        def hungarian(a):  # Time: O(n^2 * m), Space: O(n + m)
            if not a:
                return 0, []
            n, m = len(a)+1, len(a[0])+1
            u, v, p, ans = [0]*n, [0]*m, [0]*m, [0]*(n-1)
            for i in xrange(1, n):
                p[0] = i
                j0 = 0  # add "dummy" worker 0
                dist, pre = [float("inf")]*m, [-1]*m
                done = [False]*(m+1)
                while True:  # dijkstra
                    done[j0] = True
                    i0, j1, delta = p[j0], None, float("inf")
                    for j in xrange(1, m):
                        if done[j]:
                            continue
                        cur = a[i0-1][j-1]-u[i0]-v[j]
                        if cur < dist[j]:
                            dist[j], pre[j] = cur, j0
                        if dist[j] < delta:
                            delta, j1 = dist[j], j
                    for j in xrange(m):
                        if done[j]:
                            u[p[j]] += delta
                            v[j] -= delta
                        else:
                            dist[j] -= delta
                    j0 = j1
                    if not p[j0]:
                        break
                while j0:  # update alternating path
                    j1 = pre[j0]
                    p[j0], j0 = p[j1], j1
            for j in xrange(1, m):
                if p[j]:
                    ans[p[j]-1] = j-1
            return -v[0], ans  # min cost
    
        return -hungarian([[-((nums[i] if i < len(nums) else 0) & (1+x//2)) for x in xrange(2*numSlots)] for i in xrange(2*numSlots)])[0]


# Time:  O(n^3)
# Space: O(n^2)
from scipy.optimize import linear_sum_assignment as hungarian
import itertools


# 3rd-party weighted bipartite matching solution
class Solution2(object):
    def maximumANDSum(self, nums, numSlots):
        """
        :type nums: List[int]
        :type numSlots: int
        :rtype: int
        """
        adj = [[-((nums[i] if i < len(nums) else 0) & (1+x//2)) for x in xrange(2*numSlots)] for i in xrange(2*numSlots)]
        return -sum(adj[i][j] for i, j in itertools.izip(*hungarian(adj)))    


# Time:  O(n * 3^n)
# Space: O(3^n)
# bottom-up dp (hard to implement but faster)
class Solution3(object):
    def maximumANDSum(self, nums, numSlots):
        """
        :type nums: List[int]
        :type numSlots: int
        :rtype: int
        """
        def count(x):
            result = 0
            while x:
                result += x%3
                x //= 3
            return result

        dp = [0]*(3**numSlots)
        for mask in xrange(1, len(dp)):
            i = count(mask)-1
            x = nums[i] if i < len(nums) else 0
            base = 1
            for slot in xrange(1, numSlots+1):
                if mask//base%3:
                    dp[mask] = max(dp[mask], (x&slot)+dp[mask-base])
                base *= 3
        return dp[-1]


# Time:  O(n * 3^n)
# Space: O(3^n)
# memoization, top-down dp (easy to implement but slower)
class Solution4(object):
    def maximumANDSum(self, nums, numSlots):
        """
        :type nums: List[int]
        :type numSlots: int
        :rtype: int
        """
        def memoiztion(i, mask):  # i is metadata, which could be derived from mask, just for shorter implementation
            if lookup[mask] != -1:
                return lookup[mask]
            x = nums[i] if i < len(nums) else 0
            base = 1
            for slot in xrange(1, numSlots+1):
                if mask//base%3:
                     lookup[mask] = max(lookup[mask], (x&slot)+memoiztion(i-1, mask-base))
                base *= 3
            return lookup[mask]
        
        lookup = [-1]*(3**numSlots)
        lookup[0] = 0
        return memoiztion(2*numSlots-1, 3**numSlots-1)
