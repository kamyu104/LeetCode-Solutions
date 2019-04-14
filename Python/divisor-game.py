# Time:  O(1)
# Space: O(1)

class Solution(object):
    def divisorGame(self, N):
        """
        :type N: int
        :rtype: bool
        """
        # 1. if Alice gets an even, she can choose x = 1
        #    to make Bob always get an odd
        # 2. if Bob gets an odd, he can only choose x = 1 or other odds
        #    and Alice can still get an even
        # 3. at the end, Bob can only choose x = 1 and Alice wins
        # 4. in summary, Alice wins if only if she gets an even and 
        #    keeps even until Bob loses
        return N % 2 == 0
