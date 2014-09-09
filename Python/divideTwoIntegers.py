# Time:  O(logn)
# Space: O(1)
# 
# Divide two integers without using multiplication, division and mod operator.
#

class Solution:
    # @return an integer
    def divide(self, dividend, divisor):
        result, a, b = 0, abs(dividend), abs(divisor)
        while a >= b:
            c = b
            i = 0
            while a >= c:
                a -= c
                result += 1 << i
                c <<= 1
                i += 1
        if dividend > 0 and divisor < 0 or dividend < 0 and divisor > 0:
            return -result
        else:
            return result
        
if __name__ == "__main__":
    print Solution().divide(123, 12)
    print Solution().divide(123, -12)
    print Solution().divide(-123, 12)
    print Solution().divide(-123, -12)