# Time:  O(m * n)
# Space: O(min(m, n))

class Solution(object):
    def maxDotProduct(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        if len(nums1) < len(nums2):
            return self.maxDotProduct(nums2, nums1)
        dp = [[0]*len(nums2) for i in xrange(2)]
        for i in xrange(len(nums1)):
            for j in xrange(len(nums2)):
                dp[i%2][j] = nums1[i]*nums2[j]
                if i and j:
                    dp[i%2][j] += max(dp[(i-1)%2][j-1], 0)
                if i:
                    dp[i%2][j] = max(dp[i%2][j], dp[(i-1)%2][j])
                if j:
                    dp[i%2][j] = max(dp[i%2][j], dp[i%2][j-1])
        return dp[(len(nums1)-1)%2][-1]
