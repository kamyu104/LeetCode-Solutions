# Time:  O(n^2)
# Space: O(n^2)

MAX_N = 1000
MOD = 10**9+7
dp = [[0]*MAX_N for _ in xrange(MAX_N)]
for i in xrange(len(dp)):
    dp[i][0] = 1
    for j in xrange(1, i+1):
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD


class Solution(object):
    def numOfWays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def iter_dfs(nums):
            result = [0]
            stk = [[1, [nums, result]]]
            while stk:
                step, params = stk.pop()
                if step == 1:
                    nums, ret = params
                    if len(nums) <= 2:
                        ret[0] = 1
                        continue
                    left = [v for v in nums if v < nums[0]]
                    right = [v for v in nums if v > nums[0]]
                    ret[0] = dp[len(left)+len(right)][len(left)]
                    ret1, ret2 = [0], [0]
                    stk.append([2, [ret1, ret2, ret]])
                    stk.append([1, [right, ret2]])
                    stk.append([1, [left, ret1]])
                elif step == 2:
                    ret1, ret2, ret = params
                    ret[0] = ret[0]*ret1[0] % MOD
                    ret[0] = ret[0]*ret2[0] % MOD
            return result[0]

        return (iter_dfs(nums)-1)%MOD


# Time:  O(n^2)
# Space: O(n^2)
class Solution(object):
    def numOfWays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def dfs(nums):
            if len(nums) <= 2:
                return 1
            left = [v for v in nums if v < nums[0]]
            right = [v for v in nums if v > nums[0]]
            result = dp[len(left)+len(right)][len(left)]
            result = result*dfs(left) % MOD
            result = result*dfs(right) % MOD
            return result

        return (dfs(nums)-1)%MOD
