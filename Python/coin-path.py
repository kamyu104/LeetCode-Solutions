# Time:  O(n * B)
# Space: O(n)

class Solution(object):
    def cheapestJump(self, A, B):
        """
        :type A: List[int]
        :type B: int
        :rtype: List[int]
        """
        result = []
        if not A or A[-1] == -1:
            return result
        n = len(A)
        dp, next_pos = [float("inf")] * n, [-1] * n
        dp[n-1] = A[n-1]
        for i in reversed(xrange(n-1)):
            if A[i] == -1:
                continue
            for j in xrange(i+1, min(i+B+1,n)):
                if A[i] + dp[j] < dp[i]:
                    dp[i] = A[i] + dp[j]
                    next_pos[i] = j
        if dp[0] == float("inf"):
            return result
        k = 0
        while k != -1:
            result.append(k+1)
            k = next_pos[k]
        return result

