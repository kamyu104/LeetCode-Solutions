# Time:  O(n^2)
# Space: O(n)
#
# The set [1,2,3,...,n] contains a total of n! unique permutations.
# 
# By listing and labeling all of the permutations in order,
# We get the following sequence (ie, for n = 3):
# 
# "123"
# "132"
# "213"
# "231"
# "312"
# "321"
# Given n and k, return the kth permutation sequence.
# 
# Note: Given n will be between 1 and 9 inclusive.
#

import math

# Cantor ordering solution
class Solution:
    # @return a string
    def getPermutation(self, n, k):
        seq, k, fact = "", k - 1, math.factorial(n - 1)
        perm = [i for i in xrange(1, n + 1)]
        for i in reversed(xrange(n)):
            curr = perm[k / fact]
            seq += str(curr)
            perm.remove(curr)
            if i > 0:
                k %= fact
                fact /= i
        return seq
    
if __name__ == "__main__":
    print Solution().getPermutation(3, 2)
