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
        bit_length = 32
        neg_bit, mask = 1 << (bit_length-1), ~(~0 << bit_length)

        a = (a | ~mask) if (a & neg_bit) else (a & mask)
        b = (b | ~mask) if (b & neg_bit) else (b & mask)

        while b:
            carry = a & b
            a ^= b
            b = carry << 1
            b = (b | ~mask) if (b & neg_bit) else (b & mask)

        return a
