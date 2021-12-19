# Time:  O(n)
# Space: O(1)

# inplace solution
class Solution(object):
    def addSpaces(self, s, spaces):
        """
        :type s: str
        :type spaces: List[int]
        :rtype: str
        """
        prev = len(s)
        s = list(s)
        s.extend([None]*len(spaces))
        for i in reversed(xrange(len(spaces))):
            for j in reversed(xrange(spaces[i], prev)):
                s[j+1+i] = s[j]
            s[spaces[i]+i] = ' '
            prev = spaces[i]
        return "".join(s)
