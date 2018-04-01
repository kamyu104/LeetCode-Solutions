# Time:  O(n)
# Space: O(logn)

# A magical string S consists of only '1' and '2' and obeys the following rules:
#
# The string S is magical because concatenating
# the number of contiguous occurrences of characters '1' and '2' generates the string S itself.
#
# The first few elements of string S is the following: S = "1221121221221121122……"
#
# If we group the consecutive '1's and '2's in S, it will be:
#
# 1 22 11 2 1 22 1 22 11 2 11 22 ......
#
# and the occurrences of '1's or '2's in each group are:
#
# 1 2	2 1 1 2 1 2 2 1 2 2 ......
#
# You can see that the occurrence sequence above is the S itself.
#
# Given an integer N as input, return the number of '1's in the first N number in the magical string S.
#
# Note: N will not exceed 100,000.
#
# Example 1:
# Input: 6
# Output: 3
# Explanation: The first 6 elements of magical string S is "12211" and it contains three 1's, so return 3.

# the solution comes from https://discuss.leetcode.com/topic/75242/o-log-n-space-using-recursive-generators

import itertools


class Solution(object):
    def magicalString(self, n):
        """
        :type n: int
        :rtype: int
        """
        def gen():  # see figure 1 on page 3 of http://www.emis.ams.org/journals/JIS/VOL15/Nilsson/nilsson5.pdf
            for c in 1, 2, 2:
                yield c
            for i, c in enumerate(gen()):
                if i > 1:
                    for _ in xrange(c):
                        yield i % 2 + 1

        return sum(c & 1 for c in itertools.islice(gen(), n))
