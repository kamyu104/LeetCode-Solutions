# Time:  O(n^2 * 2^n)
# Space: O(n * 2^n)

# backtracking, memoization
class Solution(object):
    def specialPerm(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        def backtracking(i, mask):
            if mask == (1<<len(nums))-1:
                return 1
            if lookup[i+1][mask] == -1:
                total = 0
                for j in xrange(len(nums)):
                    if mask&(1<<j):
                        continue
                    if not (i == -1 or nums[i]%nums[j] == 0 or nums[j]%nums[i] == 0):
                        continue
                    total = (total+backtracking(j, mask|(1<<j)))%MOD
                lookup[i+1][mask] = total
            return lookup[i+1][mask]

        lookup = [[-1]*(1<<len(nums)) for _ in xrange(len(nums)+1)]
        return backtracking(-1, 0)
