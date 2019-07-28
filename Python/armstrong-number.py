# Time:  O(logn * logk)
# Space: O(logn)

class Solution(object):
    def isArmstrong(self, N):
        """
        :type N: int
        :rtype: bool
        """
        n_str = str(N)
        return sum(int(i)**len(n_str) for i in n_str) == N
