# Time:  O((logn)^2) = O(1) due to n is a 32-bit number
# Space: O(logn) = O(1)

# Starting with a positive integer N,
# we reorder the digits in any order (including the original order)
# such that the leading digit is not zero.
#
# Return true if and only if we can do this in a way
# such that the resulting number is a power of 2.
#
# Example 1:
#
# Input: 1
# Output: true
# Example 2:
#
# Input: 10
# Output: false
# Example 3:
#
# Input: 16
# Output: true
# Example 4:
#
# Input: 24
# Output: false
# Example 5:
#
# Input: 46
# Output: true
#
# Note:
# - 1 <= N <= 10^9

import collections


class Solution(object):
    def reorderedPowerOf2(self, N):
        """
        :type N: int
        :rtype: bool
        """
        count = collections.Counter(str(N))
        return any(count == collections.Counter(str(1 << i))
                   for i in xrange(31))
