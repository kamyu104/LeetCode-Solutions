# Time:  O(n)
# Space: O(n)

import random


# quick select
class Solution(object):
    def maxStarSum(self, vals, edges, k):
        """
        :type vals: List[int]
        :type edges: List[List[int]]
        :type k: int
        :rtype: int
        """
        def nth_element(nums, n, compare=lambda a, b: a < b):
            def tri_partition(nums, left, right, target, compare):
                mid = left
                while mid <= right:
                    if nums[mid] == target:
                        mid += 1
                    elif compare(nums[mid], target):
                        nums[left], nums[mid] = nums[mid], nums[left]
                        left += 1
                        mid += 1
                    else:
                        nums[mid], nums[right] = nums[right], nums[mid]
                        right -= 1
                return left, right

            left, right = 0, len(nums)-1
            while left <= right:
                pivot_idx = random.randint(left, right)
                pivot_left, pivot_right = tri_partition(nums, left, right, nums[pivot_idx], compare)
                if pivot_left <= n <= pivot_right:
                    return
                elif pivot_left > n:
                    right = pivot_left-1
                else:  # pivot_right < n.
                    left = pivot_right+1

        adj = [[] for _ in xrange(len(vals))]
        for u, v in edges:
            if vals[v] > 0:
                adj[u].append(v)
            if vals[u] > 0:
                adj[v].append(u)
        result = float("-inf")
        for u in xrange(len(vals)):
            if 1 <= k <= len(adj[u]):
                nth_element(adj[u], k-1, lambda a, b: vals[a] > vals[b])
            result = max(result, vals[u]+sum(vals[adj[u][i]] for i in range(min(k, len(adj[u])))))
        return result
