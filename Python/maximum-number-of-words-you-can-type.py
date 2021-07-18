# Time:  O(n)
# Space: O(1)

class Solution(object):
    def canBeTypedWords(self, text, brokenLetters):
        """
        :type text: str
        :type brokenLetters: str
        :rtype: int
        """
        lookup = set(brokenLetters)
        result, broken = 0, False
        for c in text:
            if c == ' ':
                result += int(broken == False)
                broken = False
            elif c in lookup:
                broken = True
        return result + int(broken == False)
