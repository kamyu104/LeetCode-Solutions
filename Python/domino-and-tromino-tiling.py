# Time:  O(logn)
# Space: O(logn)

import itertools

class Solution(object):
    def numTilings(self, N):
        """
        :type N: int
        :rtype: int
        """
        M = int(1e9+7)

        def matrix_expo(A, K):
            if K == 0:
                return [[int(i==j) for j in xrange(len(A))] \
                        for i in xrange(len(A))]
            if K == 1:
                return A
            if K % 2:
                return matrix_mult(matrix_expo(A, K-1), A)
            B = matrix_expo(A, K//2)
            return matrix_mult(B, B)

        def matrix_mult(A, B):
            ZB = zip(*B)
            return [[sum(a*b for a, b in itertools.izip(row, col)) % M \
                     for col in ZB] for row in A]

        T = [[1, 0, 0, 1],  # #(|) = #(|) + #(=)
             [1, 0, 1, 0],  # #(「) = #(|) + #(L)
             [1, 1, 0, 0],  # #(L) = #(|) + #(「)
             [1, 1, 1, 0]]  # #(=) = #(|) + #(「) + #(L)

        return matrix_expo(T, N)[0][0]  # T^N * [1, 0, 0, 0]

class Solution2(object):
    def numTilings(self, N):
        """
        :type N: int
        :rtype: int
        """
        # Prove:
        # dp[n] = dp[n-1](|) + dp[n-2](=) + 2*(dp[n-3](「」) + ... + d[0](「 = ... = 」))
        #       = dp[n-1] + dp[n-2] + dp[n-3] + dp[n-3] + 2*(dp[n-4] + ... + d[0])
        #       = dp[n-1] + dp[n-3] + (dp[n-2] + dp[n-3] + 2*(dp[n-4] + ... + d[0])
        #       = dp[n-1] + dp[n-3] + dp[n-1]
        #       = 2*dp[n-1] + dp[n-3]
        M = int(1e9+7)
        dp = [1, 1, 2]
        for i in xrange(3, N+1):
            dp[i%3] = (2*dp[(i-1)%3]%M + dp[(i-3)%3])%M
        return dp[N%3]

