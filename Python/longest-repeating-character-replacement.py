# Time:  O(n)
# Space: O(1)

# Given a string that consists of only uppercase English letters,
# you can replace any letter in the string with another letter at most k times.
# Find the length of a longest substring containing all repeating letters
# you can get after performing the above operations.
#
# Note:
# Both the string's length and k will not exceed 104.
#
# Example 1:
#
# Input:
# s = "ABAB", k = 2
#
# Output:
# 4
#
# Explanation:
# Replace the two 'A's with two 'B's or vice versa.
# Example 2:
#
# Input:
# s = "AABABBA", k = 1
#
# Output:
# 4
#
# Explanation:
# Replace the one 'A' in the middle with 'B' and form "AABBBBA".
# The substring "BBBB" has the longest repeating letters, which is 4.

class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        res = 0

        cnts = [0] * 26
        times, i, j = k, 0, 0
        while j < len(s):
            cnts[ord(s[j]) - ord('A')] += 1
            if s[j] != s[i]:
                times -= 1
                if times < 0:
                    res = max(res, j - i)
                    while i < j and times < 0:
                        cnts[ord(s[i]) - ord('A')] -= 1
                        i += 1
                        times = k - (j - i + 1 - cnts[ord(s[i]) - ord('A')])
            j += 1

        return max(res, j - i + min(i, times))
