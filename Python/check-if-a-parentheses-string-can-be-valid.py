# Time:  O(n)
# Space: O(1)

class Solution(object):
    def canBeValid(self, s, locked):
        """
        :type s: str
        :type locked: str
        :rtype: bool
        """
        if len(s)%2:
            return False
        for direction, c in ((lambda x:x, '('), (reversed, ')')):
            cnt = bal = 0
            for i in direction(xrange(len(s))):
                if locked[i] == '0':
                    cnt += 1
                else:
                    bal += 1 if s[i] == c else -1
                    if cnt+bal < 0:
                        return False
        return True
