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
        result, carry, val = "", 0, 0
        for i in xrange(max(len(a), len(b))):
            val = carry
            if i < len(a):
                val += int(a[-(i + 1)])
            if i < len(b): 
                val += int(b[-(i + 1)])
            carry, val = val / 2, val % 2
            result += str(val)
        if carry == 1:
            result += "1"
        return result[::-1]

if __name__ == '__main__':
    result = Solution().addBinary('11', '1')
    print result
