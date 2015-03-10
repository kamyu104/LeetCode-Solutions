# Time:  O(m)
# Space: O(1)
#
# Write a function that takes an unsigned integer 
# and returns the number of '1' bits it has (also known as the Hamming weight).
# 
# For example, the 32-bit integer '11' has binary representation 00000000000000000000000000001011, 
# so the function should return 3.
#
# Credits:
# Special thanks to @ts for adding this problem and creating all test cases.
#
class Solution:
    # @param n, an integer
    # @return an integer
    def hammingWeight(self, n):
        result = 0
        while n:
            n &= n - 1
            result += 1
        return result

if __name__ == '__main__':
  print Solution().hammingWeight(11)
