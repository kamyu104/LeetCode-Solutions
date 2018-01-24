# Time:  O(logn) = O(1)
# Space: O(1)
#
# Reverse digits of an integer.
# 
# Example1: x = 123, return 321
# Example2: x = -123, return -321
# 
# click to show spoilers.
# 
# Have you thought about this?
# Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
# 
# If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
# 
# Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, 
# then the reverse of 1000000003 overflows. How should you handle such cases?
# 
# Throw an exception? Good, but what if throwing an exception is not an option? 
# You would then have to re-design the function (ie, add an extra parameter).


class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0:
            return -self.reverse(-x)

        result = 0
        while x:
            result = result * 10 + x % 10
            x //= 10
        return result if result <= 0x7fffffff else 0  # Handle overflow.
    
    def reverse2(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0:
            x = int(str(x)[::-1][-1] + str(x)[::-1][:-1])
        else:
            x = int(str(x)[::-1])
        x = 0 if abs(x) > 0x7FFFFFFF else x
        return x

    def reverse3(self, x):
        """
        :type x: int
        :rtype: int
        """
        s = cmp(x, 0)
        r = int(`s * x`[::-1])
        return s * r * (r < 2 ** 31)


if __name__ == "__main__":
    print Solution().reverse(123)
    print Solution().reverse(-321)
