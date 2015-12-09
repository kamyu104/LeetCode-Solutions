# Time:  O(n)
# Space: O(k), k is size of the alphabet

# Given a string which contains only lowercase letters,
# remove duplicate letters so that every letter appear
# once and only once. You must make sure your result is
# the smallest in lexicographical order among all
# possible results.
#
# Example:
# Given "bcabc"
# Return "abc"
#
# Given "cbacdcbc"
# Return "acdb"

class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        cnts = collections.defaultdict(int)
        for c in s:
            cnts[c] += 1

        visited, stk = set(), []
        for c in s:
            if c not in visited and (not stk or stk[-1] != c):
                while stk and stk[-1] >= c and cnts[stk[-1]] > 0:
                    visited.remove(stk.pop())
                stk += c
                visited.add(c)
            cnts[c] -= 1
        return "".join(stk)
