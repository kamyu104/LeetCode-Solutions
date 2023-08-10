# Time:  O(n^2)
# Space: O(n)

# greedy, sort, dp, linear search
class Solution(object):
    def minimumTime(self, nums1, nums2, x):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type x: int
        :rtype: int
        """
        dp = [0]*(len(nums1)+1)
        for i, (b, a) in enumerate(sorted(zip(nums2, nums1)), 1):
            for j in reversed(xrange(1, i+1)):
                dp[j] = max(dp[j], dp[j-1]+(a+j*b))
        total1, total2 = sum(nums1), sum(nums2)
        return next((j for j in xrange(len(dp)) if (total1+j*total2)-dp[j] <= x), -1)
