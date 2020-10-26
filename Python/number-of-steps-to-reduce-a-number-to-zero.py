# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def numberOfSteps (self, num):
        """
        :type num: int
        :rtype: int
        """
        result = 0
        while num:
            result += 2 if num%2 else 1
            num //= 2
        return max(result-1, 0)
