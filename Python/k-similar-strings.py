# Time:  O(n * n!/(c_a!*...*c_z!), n is the length of A, B,
#                                  c_a...c_z is the count of each alphabet,
#                                  n = sum(c_a...c_z)
# Space: O(n * n!/(c_a!*...*c_z!)

# Strings A and B are K-similar (for some non-negative integer K)
# if we can swap the positions of two letters
# in A exactly K times so that the resulting string equals B.
#
# Given two anagrams A and B, return the smallest K for which A and B are
# K-similar.
#
# Example 1:
#
# Input: A = "ab", B = "ba"
# Output: 1
# Example 2:
#
# Input: A = "abc", B = "bca"
# Output: 2
# Example 3:
#
# Input: A = "abac", B = "baca"
# Output: 2
# Example 4:
#
# Input: A = "aabc", B = "abca"
# Output: 2
# Note:
# - 1 <= A.length == B.length <= 20
# - A and B contain only lowercase letters from
# the set {'a', 'b', 'c', 'd', 'e', 'f'}

import collections

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3


class Solution(object):
    def kSimilarity(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: int
        """
        def neighbors(s, B):
            for i, c in enumerate(s):
                if c != B[i]:
                    break
            t = list(s)
            for j in xrange(i+1, len(s)):
                if t[j] == B[i]:
                    t[i], t[j] = t[j], t[i]
                    yield "".join(t)
                    t[j], t[i] = t[i], t[j]

        q = collections.deque([A])
        lookup = set()
        result = 0
        while q:
            for _ in xrange(len(q)):
                s = q.popleft()
                if s == B:
                    return result
                for t in neighbors(s, B):
                    if t not in lookup:
                        lookup.add(t)
                        q.append(t)
            result += 1
