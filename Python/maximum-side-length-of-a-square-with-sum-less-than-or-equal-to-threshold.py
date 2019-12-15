# Time:  O(m * n * log(min(m, n)))
# Space: O(m * n)

class Solution(object):
    def maxSideLength(self, mat, threshold):
        """
        :type mat: List[List[int]]
        :type threshold: int
        :rtype: int
        """
        def check(dp, mid, threshold):
            for i in xrange(mid, len(dp)):
                for j in xrange(mid, len(dp[0])):
                    if dp[i][j] - dp[i-mid][j] - dp[i][j-mid] + dp[i-mid][j-mid] <= threshold:
                        return True
            return False
        
        dp = [[0 for _ in xrange(len(mat[0])+1)] for _ in xrange(len(mat)+1)]
        for i in xrange(1, len(mat)+1):
            for j in xrange(1, len(mat[0])+1):
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i-1][j-1]

        left, right = 0, min(len(mat), len(mat[0])+1)
        while left <= right:
            mid = left + (right-left)//2
            if not check(dp, mid, threshold):
                right = mid-1
            else:
                left = mid+1
        return right
