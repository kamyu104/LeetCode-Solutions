# Time:  O(n)
# Space: O(1)

class Solution(object):
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        lower, upper = 0, 0  # keep lower bound and upper bound of '(' counts
        for c in s:
            if c == '(':
                lower += 1
                upper += 1
            elif c == ')':
                if upper == 0:  # '(' count is not enough
                    return False
                lower = max(lower-1, 0);
                upper -= 1
            else:
                lower = max(lower-1, 0);
                upper += 1
        return lower == 0  # range of '(' count is valid
  
