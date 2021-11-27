# Time:  O(n)
# Space: O(1)

class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        i, j = 0, len(s) - 1
        while i < j:
            s[i], s[j] = s[j], s[i]
            i += 1
            j -= 1
        return s

