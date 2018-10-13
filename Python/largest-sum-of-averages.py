# Time:  O(k * n^2)
# Space: O(n)


class Solution(object):
    def largestSumOfAverages(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: float
        """
        accum_sum = [A[0]]
        for i in xrange(1, len(A)):
            accum_sum.append(A[i]+accum_sum[-1])

        dp = [[0]*len(A) for _ in xrange(2)]
        for k in xrange(1, K+1):
            for i in xrange(k-1, len(A)):
                if k == 1:
                    dp[k % 2][i] = float(accum_sum[i])/(i+1)
                else:
                    for j in xrange(k-2, i):
                        dp[k % 2][i] = \
                            max(dp[k % 2][i],
                                dp[(k-1) % 2][j] +
                                float(accum_sum[i]-accum_sum[j])/(i-j))
        return dp[K % 2][-1]

