# Time:  O(n + r), r = max(nums)
# Space: O(n + r)

# combinatorics, stars and bars
class Solution(object):
    def countOfPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        fact, inv, inv_fact = [[1]*2 for _ in xrange(3)]
        def nCr(n, k):
            while len(inv) <= n:  # lazy initialization
                fact.append(fact[-1]*len(inv) % MOD)
                inv.append(inv[MOD%len(inv)]*(MOD-MOD//len(inv)) % MOD)  # https://cp-algorithms.com/algebra/module-inverse.html
                inv_fact.append(inv_fact[-1]*inv[-1] % MOD)
            return (fact[n]*inv_fact[n-k] % MOD) * inv_fact[k] % MOD
    
        def nHr(n, r):
            return nCr(n+r-1, r)

        MOD = 10**9+7
        # arr1 = [0+x1, arr1[0]+max(nums[1]-nums[0], 0)+x2, ..., arr[n-2]+max(nums[n-1]-nums[n-2], 0)+xn]
        # => sum(max(nums[i]-nums[i-1], 0) for i in xrange(1, len(nums)))+(x1+x2+...+xn) <= nums[-1]
        # => x1+x2+...+xn <= nums[-1]-sum(max(nums[i]-nums[i-1], 0) for i in xrange(1, len(nums))) = cnt <= min(nums)
        # => the answer is the number of solutions s.t. x1+x2+...+xn <= cnt, where cnt >= 0
        cnt = nums[-1]-sum(max(nums[i]-nums[i-1], 0) for i in xrange(1, len(nums)))
        return nHr(len(nums)+1, cnt) if cnt >= 0 else 0
    

# Time:  O(n * r), r = max(nums)
# Space: O(r)
# dp, prefix sum
class Solution2(object):
    def countOfPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        dp = [int(i <= nums[0]) for i in xrange(max(nums)+1)]  # dp[j]: numbers of arr1, which is of length i+1 and arr1[i] is j
        for i in xrange(1, len(nums)):
            # arr1[i-1] <= arr1[i]
            # => arr1[i]-arr1[i-1] >= 0 (1)
            #
            # arr2[i-1] >= arr2[i]
            # => nums[i-1]-arr1[i-1] >= nums[i]-arr1[i] 
            # => arr1[i]-arr1[i-1] >= nums[i]-nums[i-1] (2)
            #
            # (1)+(2): arr1[i]-arr1[i-1] >= max(nums[i]-nums[i-1], 0)
            new_dp = [0]*len(dp)
            diff = max(nums[i]-nums[i-1], 0)
            for j in xrange(diff, nums[i]+1):
                new_dp[j] = (new_dp[j-1]+dp[j-diff])%MOD
            dp = new_dp
        return reduce(lambda accu, x: (accu+x)%MOD, dp, 0)
    

# Time:  O(n * r^2), r = max(nums)
# Space: O(r)
# dp
class Solution3(object):
    def countOfPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        dp = [int(i <= nums[0]) for i in xrange(max(nums)+1)]  # dp[j]: numbers of arr1, which is of length i+1 and arr1[i] is j
        for i in xrange(1, len(nums)):
            # arr1[i-1] <= arr1[i]
            # => arr1[i]-arr1[i-1] >= 0 (1)
            #
            # arr2[i-1] >= arr2[i]
            # => nums[i-1]-arr1[i-1] >= nums[i]-arr1[i] 
            # => arr1[i]-arr1[i-1] >= nums[i]-nums[i-1] (2)
            #
            # (1)+(2): arr1[i]-arr1[i-1] >= max(nums[i]-nums[i-1], 0)
            new_dp = [0]*len(dp)
            diff = max(nums[i]-nums[i-1], 0)
            for j in xrange(diff, nums[i]+1):
                for k in xrange(diff, j+1):
                    new_dp[j] = (new_dp[j]+dp[k-diff])%MOD
            dp = new_dp
        return reduce(lambda accu, x: (accu+x)%MOD, dp, 0)
