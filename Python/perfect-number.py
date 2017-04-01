# Time:  O(sqrt(n))
# Space: O(1)

# We define the Perfect Number is a positive integer that is equal
# to the sum of all its positive divisors except itself.
#
# Now, given an integer n, write a function that returns true 
# when it is a perfect number and false when it is not.
# Example:
# Input: 28
# Output: True
# Explanation: 28 = 1 + 2 + 4 + 7 + 14
# Note: The input number n will not exceed 100,000,000. (1e8)

class Solution(object):
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False
        
        sqrt_num = int(num ** 0.5)
        total = sum(i+num//i for i in xrange(1, sqrt_num+1) if num%i == 0)
        if sqrt_num ** 2 == num:
            total -= sqrt_num
        return total - num == num
