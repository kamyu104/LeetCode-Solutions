# Time:  O(n)
# Space: O(1)

# Given two strings A and B of lowercase letters,
# return true if and only if we can swap two letters in A
# so that the result equals B.
#
# Example 1:
#
# Input: A = "ab", B = "ba"
# Output: true
# Example 2:
#
# Input: A = "ab", B = "ab"
# Output: false
# Example 3:
#
# Input: A = "aa", B = "aa"
# Output: true
# Example 4:
#
# Input: A = "aaaaaaabc", B = "aaaaaaacb"
# Output: true
# Example 5:
#
# Input: A = "", B = "aa"
# Output: false
#
# Note:
# - 0 <= A.length <= 20000
# - 0 <= B.length <= 20000
# - A and B consist only of lowercase letters.

import itertools


class Solution(object):
    def buddyStrings(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if len(A) != len(B):
            return False
        diff = []
        for a, b in itertools.izip(A, B):
            if a != b:
                diff.append((a, b))
                if len(diff) > 2:
                    return False
        return (not diff and len(set(A)) < len(A)) or \
               (len(diff) == 2 and diff[0] == diff[1][::-1])
