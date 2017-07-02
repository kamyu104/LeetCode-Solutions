# Time:  O(loga)
# Space: O(1)

# Given a positive integer a,
# find the smallest positive integer b whose multiplication of each digit equals to a.
#
# If there is no answer or the answer is not fit in 32-bit signed integer, then return 0.
#
# Example 1
# Input:
#
# 48 
# Output:
# 68
# Example 2
# Input:
#
# 15
# Output:
# 35

class Solution(object):
    def smallestFactorization(self, a):
        """
        :type a: int
        :rtype: int
        """
        if a < 2:
            return a
        result, mul = 0, 1
        for i in reversed(xrange(2, 10)):
            while a % i == 0:
                a /= i
                result = mul*i + result
                mul *= 10
        return  result if a == 1 and result < 2**31 else 0
  
