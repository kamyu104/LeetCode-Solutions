# Time:  O(n * k^2)
# Space: O(n * k)
# if k is large, the per-merge cyclic convolution can be done in O(klogk) via NTT + CRT, Time: O(n * klogk), Space: O(n * k) in total

# topological sort, tree dp
class Solution(object):
    def countValidSubsets(self, parent, nums, k):
        """
        :type parent: List[int]
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        def merge(a, b):
            result = [0]*k
            for i in xrange(k):
                if not a[i]:
                    continue
                for j in xrange(k):
                    if not b[j]:
                        continue
                    result[(i+j)%k] = (result[(i+j)%k]+a[i]*b[j])%MOD
            return result

        adj = [[] for _ in xrange(len(nums))]
        for v in xrange(1, len(parent)):
            adj[parent[v]].append(v)
        dp = [[[0]*k for _ in xrange(2)] for _ in xrange(len(nums))]
        for u in reversed(xrange(len(nums))):
            new_dp = [[0]*k for _ in xrange(2)]
            new_dp[0][0] = 1
            new_dp[1][nums[u]%k] = 1
            for v in adj[u]:
                new_dp[0] = merge(new_dp[0], [(dp[v][0][i]+dp[v][1][i])%MOD for i in xrange(k)])
                new_dp[1] = merge(new_dp[1], dp[v][0])
            dp[u] = new_dp
        return (dp[0][0][0]+dp[0][1][0]-1)%MOD
