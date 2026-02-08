# Time:  O(n * m * k)
# Space: O(min(n, m) * k)

# dp
class Solution(object):
    def maxScore(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: int
        """
        NEG_INF = float("-inf")
        if len(nums1) < len(nums2):
            nums1, nums2 = nums2, nums1
        dp = [[NEG_INF]*(k+1) for _ in xrange(len(nums2)+1)]
        for j in xrange(len(nums2)+1):
            dp[j][0] = 0
        new_dp = [[NEG_INF]*(k+1) for _ in xrange(len(nums2)+1)]
        for i in xrange(len(nums1)):
            for j in xrange(len(nums2)+1):
                new_dp[j][0] = 0
            for j in xrange(len(nums2)):
                score = nums1[i]*nums2[j]
                for c in xrange(min(i+1, j+1, k)):
                    new_dp[j+1][c+1] = max(
                        new_dp[j][c+1],
                        dp[j+1][c+1],
                        dp[j][c]+score
                    )
            dp, new_dp = new_dp, dp
        return dp[-1][-1]


# Time:  O(n * m * k)
# Space: O(n * m)
# dp
class Solution(object):
    def maxScore(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: int
        """
        NEG_INF = float("-inf")        
        dp = [[NEG_INF]*len(nums2) for _ in xrange(len(nums1))]
        new_dp = [[NEG_INF]*len(nums2) for _ in xrange(len(nums1))]
        for c in xrange(k):
            for i in xrange(c, len(nums1)):
                for j in xrange(c, len(nums2)):
                    new_dp[i][j] = max(
                        new_dp[i][j-1] if j-1 >= c else NEG_INF,
                        new_dp[i-1][j] if i-1 >= c else NEG_INF,
                        (dp[i-1][j-1] if c else 0) + nums1[i]*nums2[j]
                    )
            dp, new_dp = new_dp, dp
        return dp[-1][-1]
