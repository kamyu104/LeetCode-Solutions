# Time:  O(n^4)
# Space: O(n)

# We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)".
# Then, we removed all commas, decimal points, and spaces,
# and ended up with the string S.
# Return a list of strings representing all possibilities for
# what our original coordinates could have been.
#
# Our original representation never had extraneous zeroes,
# so we never started with numbers like
# "00", "0.0", "0.00", "1.0", "001", "00.01",
# or any other number that can be represented with less digits.
# Also, a decimal point within a number never occurs without
# at least one digit occuring before it,
# so we never started with numbers like ".1".
#
# The final answer list can be returned in any order.
# Also note that all coordinates in the final answer
# have exactly one space between them
# (occurring after the comma.)
#
# Example 1:
# Input: "(123)"
# Output: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
# Example 2:
# Input: "(00011)"
# Output:  ["(0.001, 1)", "(0, 0.011)"]
# Explanation:
# 0.0, 00, 0001 or 00.01 are not allowed.
# Example 3:
# Input: "(0123)"
# Output: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
# Example 4:
# Input: "(100)"
# Output: [(10, 0)]
# Explanation:
# 1.0 is not allowed.
#
# Note:
# - 4 <= S.length <= 12.
# - S[0] = "(", S[S.length - 1] = ")", and the other elements in S are digits.

import itertools

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3


class Solution(object):
    def ambiguousCoordinates(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        def make(S, i, n):
            for d in xrange(1, n+1):
                left = S[i:i+d]
                right = S[i+d:i+n]
                if ((not left.startswith('0') or left == '0')
                        and (not right.endswith('0'))):
                    yield "".join([left, '.' if right else '', right])

        return ["({}, {})".format(*cand)
                for i in xrange(1, len(S)-2)
                for cand in itertools.product(make(S, 1, i),
                                              make(S, i+1, len(S)-2-i))]
