# Time:  O(nlogr + k * n * 2^n)
# Space: O(logr + k * 2^n)

# dp, backtracing
class Solution(object):
    def concatenatedDivisibility(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        def length(x):
            l = 0
            while x:
                l += 1
                x //= 10
            return max(l, 1)

        lookup = [length(x) for x in nums]
        mx = max(lookup)
        pow10 = [0]*(mx+1)
        pow10[0] = 1%k
        for i in xrange(len(pow10)-1):
            pow10[i+1] = (pow10[i]*10)%k
        dp = [[False]*k for _ in xrange(1<<len(nums))]
        dp[-1][0] = True
        for mask in reversed(xrange(len(dp)-1)):
            for r in xrange(k):
                for i, l in enumerate(lookup):
                    if mask&(1<<i):
                        continue
                    if dp[mask|(1<<i)][(r*pow10[l]+nums[i])%k]:
                        dp[mask][r] = True
                        break
        result = []
        if not dp[0][0]:
            return result
        order = sorted((x, i) for i, x in enumerate(nums))
        mask = r = 0
        for _ in xrange(len(nums)):
            for _, i in order:
                if mask&(1<<i):
                    continue
                if dp[mask|(1<<i)][(r*pow10[lookup[i]]+nums[i])%k]:
                    result.append(nums[i])
                    mask |= 1<<i
                    r = (r*pow10[lookup[i]]+nums[i])%k
                    break
        return result
