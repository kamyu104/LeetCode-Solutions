# Time:  O(n * l)
# Space: O(1)

import collections


# freq table
class Solution(object):
    def removeAnagrams(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        result = []
        prev = None
        for x in words:
            cnt = collections.Counter(x)
            if prev and prev == cnt:
                continue
            prev = cnt
            result.append(x)
        return result


# Time:  O(n * llogl)
# Space: O(l)
import collections


# sort
class Solution2(object):
    def removeAnagrams(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        result = []
        prev = None
        for x in words:
            s = sorted(x)
            if prev and prev == s:
                continue
            prev = s
            result.append(x)
        return result
