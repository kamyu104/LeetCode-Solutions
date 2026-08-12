# Time:  O(n)
# Space: O(n)

# tree dp
class Solution(object):
    def weightedSum(self, parent, nums):
        """
        :type parent: List[int]
        :type nums: List[int]
        :rtype: int
        """
        lookup = [-1]*len(nums)
        lookup[0] = 0
        for i in xrange(1, len(nums)):
            d, j = 0, i
            while lookup[j] == -1:
                d += 1
                j = parent[j]
            d += lookup[j]
            j = i
            while lookup[j] == -1:
                lookup[j] = d
                d -= 1
                j = parent[j]
        h = max(lookup)
        return sum(nums[i]*(h-lookup[i]+1) for i in xrange(len(nums)))


# Time:  O(n)
# Space: O(n)
# dfs
class Solution2(object):
    def weightedSum(self, parent, nums):
        """
        :type parent: List[int]
        :type nums: List[int]
        :rtype: int
        """
        def iter_dfs():
            lookup = [0]*len(nums)
            stk = [(0, 0)]
            while stk:
                u, d = stk.pop()
                lookup[u] = d
                for v in reversed(adj[u]):
                    stk.append((v, d+1))
            return lookup
        
        adj = [[] for _ in xrange(len(nums))]
        for i in xrange(1, len(parent)):
            adj[parent[i]].append(i)
        lookup = iter_dfs()
        h = max(lookup)
        return sum(nums[i]*(h-lookup[i]+1) for i in xrange(len(nums)))

