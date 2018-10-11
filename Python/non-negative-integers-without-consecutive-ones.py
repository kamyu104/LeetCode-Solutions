# Time:  O(1)
# Space: O(1)

class Solution(object):
    def findIntegers(self, num):
        """
        :type num: int
        :rtype: int
        """
        dp = [0] * 32
        dp[0], dp[1] = 1, 2
        for i in xrange(2, len(dp)):
            dp[i] = dp[i-1] + dp[i-2]
        result, prev_bit = 0, 0
        for i in reversed(xrange(31)):
            if (num & (1 << i)) != 0:
                result += dp[i]
                if prev_bit == 1:
                    result -= 1
                    break
                prev_bit = 1
            else:
                prev_bit = 0
        return result + 1

