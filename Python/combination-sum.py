# Time:  O(n^m)
# Space: O(m)
#
# Given a set of candidate numbers (C) and a target number (T), 
# find all unique combinations in C where the candidate numbers sums to T.
# 
# The same repeated number may be chosen from C unlimited number of times.
# 
# Note:
# All numbers (including target) will be positive integers.
# Elements in a combination (a1, a2, ... , ak) must be in non-descending order. (ie, a1 <= a2 <= ... <= ak).
# The solution set must not contain duplicate combinations.
# For example, given candidate set 2,3,6,7 and target 7, 
# A solution set is: 
# [7] 
# [2, 2, 3] 
#

class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum(self, candidates, target):
        result = []
        self.combinationSumDFS(sorted(candidates), result, 0, [], target)
        return result
    
    def combinationSumDFS(self, candidates, result, start, intermediate, target):
        if target == 0:
            result.append(intermediate)
        while start < len(candidates) and candidates[start] <= target:
            self.combinationSumDFS(candidates, result, start, intermediate + [candidates[start]], target - candidates[start])
            start += 1

if __name__ == "__main__":
    candidates, target = [2, 3, 6, 7], 7
    result = Solution().combinationSum(candidates, target)     
    print result       
