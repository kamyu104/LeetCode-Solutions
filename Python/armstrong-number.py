# Time:  O(klogk)
# Space: O(k)

class Solution(object):
    def isArmstrong(self, N):
        """
        :type N: int
        :rtype: bool
        """
        n_str = str(N)
        return sum(int(i)**len(n_str) for i in n_str) == N
