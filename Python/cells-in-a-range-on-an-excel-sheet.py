# Time:  O(26^2)
# Space: O(1)

# enumeration
class Solution(object):
    def cellsInRange(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        return [chr(x)+chr(y) for x in xrange(ord(s[0]), ord(s[3])+1) for y in xrange(ord(s[1]), ord(s[4])+1)]
