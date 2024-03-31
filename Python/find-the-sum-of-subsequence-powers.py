# Time:  O(n^2 + len(diffs) * n * k) = O(n^3 * k) at most
# Space: O(len(diffs) + n * k) = O(n^2) at most

# sort, dp, prefix sum, two pointers
class Solution(object):
    def sumOfPowers(self, nums, k):
        MOD = 10**9+7
        nums.sort()
        result = prev = 0
        for mn in sorted({nums[j]-nums[i] for i in xrange(len(nums)) for j in xrange(i+1, len(nums))}, reverse=True):
            dp = [[0]*(k+1) for _ in xrange(len(nums)+1)]
            dp[0][0] = 1
            j = 0
            for i in xrange(len(nums)):
                j = next((j for j in xrange(j, len(nums)) if nums[i]-nums[j] < mn), len(nums))
                for l in xrange(1, k+1):
                    dp[i+1][l] = (dp[i+1][l]+dp[(j-1)+1][l-1])%MOD  # dp[i+1][l]: count of subsequences of length l ending at i having min diff >= mn
                for l in xrange(k+1):
                    dp[i+1][l] = (dp[i+1][l]+dp[i][l])%MOD  # dp[i+1][l]: accumulated count of subsequences of length l ending at [0, i] having min diff >= mn
            cnt = (dp[-1][k]-prev)%MOD
            result = (result+mn*cnt)%MOD
            prev = dp[-1][k]
        return result


# Time:  O(n^3 * len(diffs)) = O(n^5) at most
# Space: O(n^2 * len(diffs)) = O(n^4) at most
import collections


# sort, dp
class Solution2(object):
    def sumOfPowers(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        nums.sort()
        dp = [[collections.defaultdict(int) for _ in xrange(len(nums)+1)] for _ in xrange(len(nums))]        
        for i in xrange(len(nums)):
            for j in xrange(max(k-(len(nums)-i+1)-1, 0), i):
                diff = nums[i]-nums[j]
                dp[i][2][diff] += 1
                for l in xrange(max(k-(len(nums)-i+1), 0), i+1):
                    for mn, cnt in dp[j][l].iteritems():
                        dp[i][l+1][min(diff, mn)] = (dp[i][l+1][min(diff, mn)]+cnt)%MOD
        return reduce(lambda accu, x: (accu+x)%MOD, ((mn*cnt)%MOD for i in xrange(k-1, len(dp)) for mn, cnt in dp[i][k].iteritems()))
