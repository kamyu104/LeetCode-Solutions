# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def countAsterisks(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = cnt = 0
        for c in s:
            if c == '|':
                cnt = (cnt+1)%2
                continue
            if c == '*' and cnt == 0:
                result += 1
        return result
