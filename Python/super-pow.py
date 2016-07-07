# Time:  O(n), n is the size of b.
# Space: O(1)

# Your task is to calculate a^b mod 1337 where a is a positive integer
# and b is an extremely large positive integer given in the form of an array.
#
# Example1:
#
# a = 2
# b = [3]
#
# Result: 8
# Example2:
#
# a = 2
# b = [1,0]
#
# Result: 1024

class Solution(object):
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        def myPow(a, n, b):
            result = 1
            x = a % b
            while n:
                if n & 1:
                    result = result * x % b
                n >>= 1
                x = x * x % b
            return result % b

        result = 1
        for digit in b:
            result = myPow(result, 10, 1337) * myPow(a, digit, 1337) % 1337
        return result
