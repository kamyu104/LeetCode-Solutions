# Time:  O(m * n)
# Space: O(m + n)
#
# Given two numbers represented as strings, return multiplication of the numbers as a string.
# 
# Note: The numbers can be arbitrarily large and are non-negative.
#

class Solution:
    # @param num1, a string
    # @param num2, a string
    # @return a string
class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        num1, num2 = num1[::-1], num2[::-1]
        res = [0] * (len(num1) + len(num2))
        for i in xrange(len(num1)):
            for j in xrange(len(num2)):
                res[i + j] += int(num1[i]) * int(num2[j])
                res[i + j + 1] += res[i + j] / 10
                res[i + j] %= 10

        res.reverse()

        # Skip leading 0s.
        i = 0
        while i < len(res) and res[i] == 0:
            i += 1

        res = ''.join(map(str, res[i:]))
        return res if res else "0"

if __name__ == "__main__":
    print Solution().multiply("123", "1000")
