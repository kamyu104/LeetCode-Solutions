# Time:  O(1)
# Space: O(1)

# Calculate the sum of two integers a and b,
# but you are not allowed to use the operator + and -.
#
# Example:
# Given a = 1 and b = 2, return 3.

class Solution(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        while b and b != 1 << 32:
            carry = a & b
            a ^= b
            b = carry << 1
        return a if b != 1 << 32 else a & 0xffffffff
