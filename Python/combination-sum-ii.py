# # Time:  O(n)
# # Space: O(n)
# 
# Given a collection of candidate numbers (C) and a target number (T), 
# find all unique combinations in C where the candidate numbers sums to T.
# 
# Each number in C may only be used once in the combination.
# 
# Note:
# All numbers (including target) will be positive integers.
# Elements in a combination (a1, a2, ... , ak) must be in non-descending order. (ie, a1 <= a2 <= ... <= ak).
# The solution set must not contain duplicate combinations.
# For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
# A solution set is: 
# [1, 7] 
# [1, 2, 5] 
# [2, 6] 
# [1, 1, 6]
#

class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum2(self, candidates, target):
        result = []
        self.combinationSumDFS(sorted(candidates), result, 0, [], target)
        return result
    
    def combinationSumDFS(self, candidates, result, start, intermediate, target):
        if target == 0:
            result.append(intermediate)
        prev = 0
        while start < len(candidates) and candidates[start] <= target:
            if prev != candidates[start]:
                self.combinationSumDFS(candidates, result, start + 1, intermediate + [candidates[start]], target - candidates[start])
                prev = candidates[start]
            start += 1

if __name__ == "__main__":
    candidates, target = [10, 1, 2, 7, 6, 1, 5], 8
    result = Solution().combinationSum2(candidates, target)     
    print result       