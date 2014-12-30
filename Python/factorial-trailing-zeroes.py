# Time:  O(logn)
# Space: O(1)
#
# Given an integer n, return the number of trailing zeroes in n!.
# 
# Note: Your solution should be in logarithmic time complexity.
#

class Solution:
    # @return an integer
    def trailingZeroes(self, n):
        result = 0
        while n > 0:
            result += n / 5
            n /= 5
        return result

if __name__ == "__main__":
    print Solution().trailingZeroes(100)