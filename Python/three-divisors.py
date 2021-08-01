# Time:  O(sqrt(n))
# Space: O(1)

class Solution(object):
    def isThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        cnt = 0
        i = 1
        while i*i <= n and cnt <= 3:
            if n%i == 0:
                cnt += 1 if i*i == n else 2
            i += 1
        return cnt == 3
