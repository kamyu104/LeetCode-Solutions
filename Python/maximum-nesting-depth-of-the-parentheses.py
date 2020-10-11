# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maxDepth(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = curr = 0
        for c in s:
            if c == '(':
                curr += 1
                result = max(result, curr)
            elif c == ')':
                curr -= 1
        return result
