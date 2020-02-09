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
            if num%2:
                num -= 1
            else:
                num //= 2
            result += 1
        return result
