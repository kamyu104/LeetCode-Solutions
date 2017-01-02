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
        neg_bit, mask = (1 << bit_length) >> 1, ~(~0 << bit_length)

        a = (a | ~mask) if (a & neg_bit) else (a & mask)
        b = (b | ~mask) if (b & neg_bit) else (b & mask)

        while b:
            carry = a & b
            a ^= b
            a = (a | ~mask) if (a & neg_bit) else (a & mask)
            b = carry << 1
            b = (b | ~mask) if (b & neg_bit) else (b & mask)

        return a

    def getSum2(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        # 32 bits integer max
        MAX = 0x7FFFFFFF
        # 32 bits interger min
        MIN = 0x80000000
        # mask to get last 32 bits
        mask = 0xFFFFFFFF
        while b:
            # ^ get different bits and & gets double 1s, << moves carry
            a, b = (a ^ b) & mask, ((a & b) << 1) & mask
        # if a is negative, get a's 32 bits complement positive first
        # then get 32-bit positive's Python complement negative
        return a if a <= MAX else ~(a ^ mask)

    def minus(self, a, b):
        b = self.getSum(~b, 1)
        return self.getSum(a, b)

    def multiply(self, a, b):
        isNeg = (a > 0) ^ (b > 0)
        x = a if a > 0 else self.getSum(~a, 1)
        y = b if b > 0 else self.getSum(~b, 1)
        ans = 0
        while y & 0x01:
            ans = self.getSum(ans, x)
            y >>= 1
            x <<= 1
        return self.getSum(~ans, 1) if isNeg else ans

    def divide(self, a, b):
        isNeg = (a > 0) ^ (b > 0)
        x = a if a > 0 else self.getSum(~a, 1)
        y = b if b > 0 else self.getSum(~b, 1)
        ans = 0
        for i in range(31, -1, -1):
            if (x >> i) >= y:
                x = self.minus(x, y << i)
                ans = self.getSum(ans, 1 << i)
        return self.getSum(~ans, 1) if isNeg else ans

