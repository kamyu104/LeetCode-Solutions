# Time:  O(k), where k is the steps to be happy number
# Space: O(k)
#
# Write an algorithm to determine if a number is "happy".
#
# A happy number is a number defined by the following process: 
# Starting with any positive integer, replace the number by the sum 
# of the squares of its digits, and repeat the process until 
# the number equals 1 (where it will stay), or it loops endlessly 
# in a cycle which does not include 1. Those numbers for which 
# this process ends in 1 are happy numbers.
#
# Example: 19 is a happy number
#
# 1^2 + 9^2 = 82
# 8^2 + 2^2 = 68
# 6^2 + 8^2 = 100
# 1^2 + 0^2 + 0^2 = 1
#
class Solution:
    # @param {integer} n
    # @return {boolean}
    def isHappy(self, n):
        lookup = {}
        while n != 1 and n not in lookup:
            lookup[n] = True
            n = self.nextNumber(n)
        return n == 1
    
    def nextNumber(self, n):
        new = 0
        for char in str(n):
            new += int(char)**2
        return new
