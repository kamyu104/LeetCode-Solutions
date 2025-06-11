# Time:  O(nlogn * logr), r = max(nums)
# Space: O(n + logr)

# number theory, suffix-gcd states, dp, binary search
class Solution(object):
    def maxGCDScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a
    
        lookup = [0]*len(nums)
        for i in xrange(len(nums)):
            while nums[i]&1 == 0:
                nums[i] >>= 1
                lookup[i] += 1
        lookup2 = [[] for _ in xrange(max(lookup)+1)]
        for i, e in enumerate(lookup):
            lookup2[e].append(i)
        result = 0
        dp = {}
        for i, x in enumerate(nums):
            new_dp = {}
            new_dp[x, lookup[i]] = [i]*2
            for (g, e), v in dp.iteritems():  # |g * e| = O(logr)
                ng = gcd(g, x)
                ne = min(e, lookup[i])
                if (ng, ne) not in new_dp:
                    new_dp[ng, ne] = [float("inf")]*2
                new_dp[ng, ne][0] = min(new_dp[ng, ne][0], v[0])
                left = bisect_left(lookup2[ne], v[0])  # Time: O(logn)
                right = bisect_right(lookup2[ne], i)-1  # Time: O(logn)
                new_dp[ng, ne][1] = min(new_dp[ng, ne][1], v[0] if right-left+1 <= k else lookup2[ne][right-k]+1)
            dp = new_dp
            for (g, e), v in dp.iteritems():  # |g * e| = O(logr)
                result = max(result, g*(i-v[0]+1)<<e, g*(i-v[1]+1)<<(e+1))
        return result


# Time:  O(n^2 + n * logr), r = max(nums)
# Space: O(1)
# number theory, brute force
class Solution2(object):
    def maxGCDScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        def lower_bit(x):
            return x&-x

        result = 0
        for i in xrange(len(nums)):
            mn = float("inf")
            g = cnt = 0
            for j in xrange(i, len(nums)):
                g = gcd(g, nums[j])
                bit = lower_bit(nums[j])
                if bit < mn:
                    mn = bit
                    cnt = 0
                if bit == mn:
                    cnt += 1
                result = max(result, g*(j-i+1)*(2 if cnt <= k else 1))
                if g*(len(nums)-i)*2 <= result:
                    break
        return result

