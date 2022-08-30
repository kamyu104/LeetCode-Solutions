# Time:  O(n)
# Space: O(n)

# stack
class Solution(object):
    def removeStars(self, s):
        """
        :type s: str
        :rtype: str
        """
        result = []
        for c in s:
            if c == '*':
                result.pop()
            else:
                result.append(c)
        return "".join(result)
