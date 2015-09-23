# Time:  O(n)
# Space: O(1)
#
# Given two binary strings, return their sum (also a binary string).
#
# For example,
# a = "11"
# b = "1"
# Return "100".
#

class Solution:
    # @param a, a string
    # @param b, a string
    # @return a string
    def addBinary(self, a, b):
        result, carry, val, len_a, len_b, i = "", 0, 0, len(a), len(b), 0
        for i in xrange(max(len_a, len_b)):
            val = carry
            if i < len_a:
                val += int(a[-(i + 1)])
            if i < len_b: 
                val += int(b[-(i + 1)])
            carry, val = val / 2, val % 2
            result += str(val)
        if carry == 1:
            result += "1"
        return result[::-1]

if __name__ == '__main__':
    result = Solution().addBinary('11', '1')
    print result
