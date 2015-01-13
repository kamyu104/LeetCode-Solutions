# Time:  O(n^2)
# Space: O(n)
#
# Given a list of non negative integers, arrange them such that they form the largest number.
# 
# For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
# 
# Note: The result may be very large, so you need to return a string instead of an integer.
#

class Solution:
    # @param num, a list of integers
    # @return a string
    def largestNumber(self, num):
        num = [str(x) for x in num]
        num.sort(cmp=lambda x, y: cmp(y + x, x + y))
        largest = ''.join(num)
        return largest.lstrip('0') or '0'

if __name__ == "__main__":
    num = [3, 30, 34, 5, 9]
    print Solution().largestNumber(num) 
