# Time:  O(qlogm + (q + n) * sqrt(n))
# Space: O(n * sqrt(n))

import collections


# sqrt decomposition, difference array, fast exponentiation
class Solution(object):
    def xorAfterQueries(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: int
        """
        MOD = 10**9+7
        def inv(x):
            return pow(x, MOD-2, MOD)

        block_size = int(len(nums)**0.5)+1
        diffs = collections.defaultdict(lambda: [1]*len(nums))
        for l, r, k, v in queries:
            if k <= block_size:
                diffs[k][l] = (diffs[k][l]*v)%MOD
                r += k-(r-l)%k
                if r < len(nums):
                    diffs[k][r] = (diffs[k][r]*inv(v))%MOD
            else:
                for i in xrange(l, r+1, k):
                    nums[i] = (nums[i]*v)%MOD
        for k, diff in diffs.iteritems():
            for i in xrange(len(diff)):
                if i-k >= 0:
                    diff[i] = (diff[i]*diff[i-k])%MOD
                nums[i] = (nums[i]*diff[i])%MOD
        return reduce(lambda accu, x: accu^x, nums, 0)


# Time:  O(q * n)
# Space: O(1)
# simulation
class Solution2(object):
    def xorAfterQueries(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: int
        """
        MOD = 10**9+7

        for l, r, k, v in queries:
            for i in xrange(l, r+1, k):
                nums[i] = (nums[i]*v)%MOD
        return reduce(lambda accu, x: accu^x, nums, 0)
