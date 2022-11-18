# Time:  O(n * sqrt(k) * logk)
# Space: O(sqrt(k))

import collections


# dp
class Solution(object):
    def subarrayLCM(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        def lcm(a, b):
            return a//gcd(a, b)*b

        result = 0
        dp = collections.Counter()
        for x in nums:
            new_dp = collections.Counter()
            if k%x == 0:
                dp[x] += 1
                for l, cnt in dp.iteritems():
                    new_dp[lcm(l, x)] += cnt
            dp = new_dp
            result += dp[k]
        return result


# Time:  O(n^2)
# Space: O(1)
# brute force
class Solution2(object):
    def subarrayLCM(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        def lcm(a, b):
            return a//gcd(a, b)*b

        result = 0
        for i in xrange(len(nums)):
            l = 1
            for j in xrange(i, len(nums)):
                if k%nums[j]:
                    break
                l = lcm(l, nums[j])
                result += int(l == k)
        return result
