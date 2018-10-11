from __future__ import print_function
# Time:  O(logn) = O(32)
# Space: O(1)

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
  print(Solution().hammingWeight(11))

