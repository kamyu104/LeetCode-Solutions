# Time:  O(k * C(n, k))
# Space: O(k)

class Solution(object):
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum2(self, candidates, target):
        result = []
        self.combinationSumRecu(sorted(candidates), result, 0, [], target)
        return result

    def combinationSumRecu(self, candidates, result, start, intermediate, target):
        if target == 0:
            result.append(list(intermediate))
        prev = 0
        while start < len(candidates) and candidates[start] <= target:
            if prev != candidates[start]:
                intermediate.append(candidates[start])
                self.combinationSumRecu(candidates, result, start + 1, intermediate, target - candidates[start])
                intermediate.pop()
                prev = candidates[start]
            start += 1

