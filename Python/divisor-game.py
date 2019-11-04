# Time:  O(1)
# Space: O(1)

class Solution(object):
    def divisorGame(self, N):
        """
        :type N: int
        :rtype: bool
        """
        # 1. if we get an even, we can choose x = 1
        #    to make the opponent always get an odd
        # 2. if the opponent gets an odd, he can only choose x = 1 or other odds
        #    and we can still get an even
        # 3. at the end, the opponent can only choose x = 1 and we win
        # 4. in summary, we win if only if we get an even and 
        #    keeps even until the opponent loses
        return N % 2 == 0


# Time:  O(n^3/2)
# Space: O(n)
# dp solution
class Solution2(object):
    def divisorGame(self, N):
        """
        :type N: int
        :rtype: bool
        """
        def memoization(N, dp):
            if N == 1:
                return False
            if N not in dp:
                result = False
                for i in xrange(1, N+1):
                    if i*i > N:
                        break
                    if N % i == 0:
                        if not memoization(N-i, dp):
                            result = True
                            break
                dp[N] = result
            return dp[N]
        
        return memoization(N, {})
