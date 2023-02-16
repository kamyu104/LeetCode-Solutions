# Time:  O(n)
# Space: O(n)

# two pointers, dp
class Solution(object):
    def minimumScore(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        right = [-1]*len(s)  # right[i]: min removed rightmost index in s[i:]
        j = len(t)-1
        for i in reversed(xrange(len(s))):
            if j >= 0 and t[j] == s[i]:
                j -= 1
            right[i] = j
        result = j+1
        left = 0  # left at i: max removed leftmost index in s[:i]
        for i in xrange(len(s)):
            result = max(min(result, right[i]-left+1), 0)
            if left < len(t) and t[left] == s[i]:
                left += 1
        result = min(result, len(t)-left)
        return result
