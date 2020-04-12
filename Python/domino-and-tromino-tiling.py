# Time:  O(logn)
# Space: O(1)

import itertools


class Solution(object):
    def numTilings(self, N):
        """
        :type N: int
        :rtype: int
        """
        M = int(1e9+7)

        def matrix_expo(A, K):
            result = [[int(i==j) for j in xrange(len(A))] \
                      for i in xrange(len(A))]
            while K:
                if K % 2:
                    result = matrix_mult(result, A)
                A = matrix_mult(A, A)
                K /= 2
            return result

        def matrix_mult(A, B):
            ZB = zip(*B)
            return [[sum(a*b for a, b in itertools.izip(row, col)) % M \
                     for col in ZB] for row in A]

        T = [[1, 0, 0, 1],  # #(|) = #(|) + #(=)
             [1, 0, 1, 0],  # #(「) = #(|) + #(L)
             [1, 1, 0, 0],  # #(L) = #(|) + #(「)
             [1, 1, 1, 0]]  # #(=) = #(|) + #(「) + #(L)

        return matrix_mult([[1, 0, 0, 0]], matrix_expo(T, N))[0][0] # [a0, a(-1), a(-2), a(-3)] * T^N


# Time:  O(n)
# Space: O(1)
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
