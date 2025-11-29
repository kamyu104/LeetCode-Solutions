# Time:  O((n + r) * logr), r = max(nums)
# Space: O(n + r)

# sos dp, principle of inclusion and exclusion
class Solution(object):
    def countEffective(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        total = reduce(lambda accu, x: accu|x, nums, 0)
        bits = [i for i in xrange(total.bit_length()) if total&(1<<i)]
        dp = [0]*(1<<len(bits))
        for x in nums:
            mask = 0
            for i in xrange(len(bits)):
                if x&(1<<bits[i]):
                    mask |= 1<<i
            dp[mask] += 1
        for i in xrange(len(bits)):
            for mask in xrange(len(dp)):
                if mask&(1<<i):
                    dp[mask] += dp[mask^(1<<i)]
        cnt = [0]*(1<<len(bits))
        for mask in xrange(1, len(cnt)):
            cnt[mask] = cnt[mask&(mask-1)]+1
        pow2 = [0]*(len(nums)+1)
        pow2[0] = 1
        for i in xrange(len(nums)):
            pow2[i+1] = (pow2[i]*2)%MOD
        full = (1<<len(bits))-1
        return reduce(lambda accu, x: (accu+x)%MOD, ((1 if cnt[mask]&1 else -1)*pow2[dp[full^mask]] for mask in xrange(1, len(cnt))), 0)
