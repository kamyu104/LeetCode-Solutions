# Time:  O(logn) = O(1)
# Space: O(1)
# 
# Divide two integers without using multiplication, division and mod operator.
#

class Solution:
    # @return an integer
    def divide(self, dividend, divisor):
        result, dvd, dvs = 0, abs(dividend), abs(divisor)
        while dvd >= dvs:
            inc = dvs
            i = 0
            while dvd >= inc:
                dvd -= inc
                result += 1 << i
                inc <<= 1
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
