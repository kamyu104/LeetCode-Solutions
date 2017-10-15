# Time:  O(n*2^n)
# Space: O(2^n)

# Given an array of integers nums and a positive integer k,
# find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.
#
# Example 1:
# Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
# Output: True
# Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
# Note:
#
# 1 <= k <= len(nums) <= 16.
# 0 < nums[i] < 10000.

# Memoization solution.
class Solution(object):
    def canPartitionKSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        def dfs(nums, target, used, todo, lookup):
            if lookup[used] is None:
                targ = (todo-1)%target + 1
                lookup[used] = any(dfs(nums, target, used | (1<<i), todo-num, lookup) \
                                   for i, num in enumerate(nums) \
                                   if ((used>>i) & 1) == 0 and num <= targ)
            return lookup[used]
        
        total = sum(nums)
        if total%k or max(nums) > total//k:
            return False
        lookup = [None] * (1 << len(nums))
        lookup[-1] = True
        return dfs(nums, total//k, 0, total, lookup)
    
    
# Time:  O(k^(n-k) * k!)
# Space: O(n)
# DFS solution with pruning.
class Solution2(object):
    def canPartitionKSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        def dfs(nums, target, i, subset_sums):
            if i == len(nums):
                return True
            for k in xrange(len(subset_sums)):
                if subset_sums[k]+nums[i] > target:
                    continue
                subset_sums[k] += nums[i]
                if dfs(nums, target, i+1, subset_sums):
                    return True
                subset_sums[k] -= nums[i]
                if not subset_sums[k]: break
            return False

        total = sum(nums)
        if total%k != 0 or max(nums) > total//k:
            return False
        nums.sort(reverse=True)
        subset_sums = [0] * k
        return dfs(nums, total/k, 0, subset_sums)
