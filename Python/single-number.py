# Time:  O(n)
# Space: O(1)
#
# Given an array of integers, every element appears twice except for one. Find that single one.
# 
# Note:
# Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
#

import operator

class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        return reduce(operator.xor, A)

if __name__ == '__main__':
    print Solution().singleNumber([1, 1, 2, 2, 3])