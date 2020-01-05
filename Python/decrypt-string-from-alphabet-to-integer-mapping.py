# Time:  O(n)
# Space: O(1)

# forward solution
class Solution(object):
    def freqAlphabets(self, s):
        """
        :type s: str
        :rtype: str
        """
        def alpha(num):
            return chr(ord('a') + int(num)-1)

        i = 0
        result = []
        while i < len(s):
            if i+2 < len(s) and s[i+2] == '#':
                result.append(alpha(s[i:i+2]))
                i += 3
            else:
                result.append(alpha(s[i]))
                i += 1
        return "".join(result)


# Time:  O(n)
# Space: O(1)
# backward solution
class Solution2(object):
    def freqAlphabets(self, s):
        """
        :type s: str
        :rtype: str
        """
        def alpha(num):
            return chr(ord('a') + int(num)-1)

        i = len(s)-1
        result = []
        while i >= 0:
            if s[i] == '#':
                result.append(alpha(s[i-2:i]))
                i -= 3
            else:
                result.append(alpha(s[i]))
                i -= 1
        return "".join(reversed(result))

# Time:  O(n)
# Space: O(1)
import re


# regex solution
class Solution3(object):
    def freqAlphabets(self, s):
        """
        :type s: str
        :rtype: str
        """
        def alpha(num):
            return chr(ord('a') + int(num)-1)

        return "".join(alpha(i[:2]) for i in re.findall(r"\d\d#|\d", s))
