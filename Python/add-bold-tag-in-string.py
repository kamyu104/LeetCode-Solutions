# Time:  O(s * d * l), l is the average string length
# Space: O(s)

class Solution(object):
    def addBoldTag(self, s, dict):
        """
        :type s: str
        :type dict: List[str]
        :rtype: str
        """
        bold = [0] * len(s)
        for d in dict:
            pos = s.find(d)
            while pos != -1:
                bold[pos:pos+len(d)] = [1] * len(d)
                pos = s.find(d, pos + 1)

        result, prev = [], 0
        for i in xrange(len(s)):
            if prev != bold[i]:
                result += "</b>" if prev else "<b>"
                prev = bold[i]
            result += s[i]
        if prev:
            result += "</b>"
        return "".join(result)
