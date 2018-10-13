# Time:  O(n)
# Space: O(n)

import collections

class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        dict, rolling_hash, res = {}, 0, []

        for i in xrange(len(s)):
            rolling_hash = ((rolling_hash << 3) & 0x3fffffff) | (ord(s[i]) & 7)
            if rolling_hash not in dict:
                dict[rolling_hash] = True
            elif dict[rolling_hash]:
                res.append(s[i - 9: i + 1])
                dict[rolling_hash] = False
        return res

    def findRepeatedDnaSequences2(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        l, r = [], []
        if len(s) < 10: return []
        for i in range(len(s) - 9):
            l.extend([s[i:i + 10]])
        return [k for k, v in collections.Counter(l).items() if v > 1]


