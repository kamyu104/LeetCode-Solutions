# Time:  O(n)
# Space: O(n)

class Solution(object):
    def smallestMissingValueSubtree(self, parents, nums):
        """
        :type parents: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """
        def iter_dfs(adj, nums, i, lookup):
            stk = [i]
            while stk:
                i = stk.pop()
                if nums[i] in lookup:
                    continue
                lookup.add(nums[i])
                for j in adj[i]:
                    stk.append(j)

        result = [1]*len(parents)
        if 1 not in nums:
            return result
        adj = [[] for i in xrange(len(parents))]
        for i in xrange(1, len(parents)):
            adj[parents[i]].append(i)
        lookup = set()
        i, miss = nums.index(1), 1
        while i >= 0:
            iter_dfs(adj, nums, i, lookup)
            while miss in lookup:
                miss += 1
            result[i] = miss
            i = parents[i]
        return result
