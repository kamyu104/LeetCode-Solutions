# Time:  O(n)
# Space: O(1)

class Solution(object):
    def sortString(self, s):
        """
        :type s: str
        :rtype: str
        """
        result, count = [], [0]*26
        for c in s:
            count[ord(c)-ord('a')] += 1
        while len(result) != len(s):
            for c in xrange(len(count)):
                if not count[c]:
                    continue
                result.append(chr(ord('a')+c))
                count[c] -= 1
            for c in reversed(xrange(len(count))):
                if not count[c]:
                    continue
                result.append(chr(ord('a')+c))
                count[c] -= 1
        return "".join(result)


# Time:  O(n)
# Space: O(1)
import collections


class Solution2(object):
    def sortString(self, s):
        """
        :type s: str
        :rtype: str
        """
        result, count, desc = [], collections.Counter(s), False
        while count:
            for c in sorted(count.keys(), reverse=desc):
                result.append(c)
                count[c] -= 1
                if not count[c]:
                    del count[c]
            desc = not desc
        return "".join(result)

