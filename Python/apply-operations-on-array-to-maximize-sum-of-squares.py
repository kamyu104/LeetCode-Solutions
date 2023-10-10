# Time:  O(nlogr), r = max(nums)
# Space: O(logr)

# bit manipulation, greedy, freq table
class Solution(object):
    def maxSum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        l = max(nums).bit_length()
        cnt = [0]*l
        for i in xrange(l):
            for x in nums:
                if x&(1<<i):
                    cnt[i] += 1
        return reduce(lambda x, y: (x+y)%MOD, (sum(1<<i for i in xrange(l) if cnt[i] >= j)**2 for j in xrange(1, k+1)))
