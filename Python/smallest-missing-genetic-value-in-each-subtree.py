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
        i = next((i for i in xrange(len(nums)) if nums[i] == 1), -1)
        if i == -1:
            return result
        adj = [[] for _ in xrange(len(parents))]
        for j in xrange(1, len(parents)):
            adj[parents[j]].append(j)
        lookup = set()
        miss = 1
        while i >= 0:
            iter_dfs(adj, nums, i, lookup)
            while miss in lookup:
                miss += 1
            result[i] = miss
            i = parents[i]
        return result
