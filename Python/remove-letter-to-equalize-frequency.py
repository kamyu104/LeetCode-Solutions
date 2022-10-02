# Time:  O(n)
# Space: O(1)

import collections


# freq table, edge cases
class Solution(object):
    def equalFrequency(self, word):
        """
        :type word: str
        :rtype: bool
        """
        cnt = collections.Counter(collections.Counter(word).itervalues())
        if len(cnt) > 2:
            return False
        if len(cnt) == 1:
            a = cnt.keys()[0]
            return a == 1 or cnt[a] == 1
        a, b = cnt.keys()
        if a > b:
            a, b = b, a
        return (a == 1 and cnt[a] == 1) or (a+1 == b and cnt[b] == 1)


# Time:  O(26 * n)
# Space: O(1)
import collections


# brute force, freq table
class Solution2(object):
    def equalFrequency(self, word):
        """
        :type word: str
        :rtype: bool
        """
        cnt = collections.Counter(collections.Counter(word))
        for c in word:
            cnt[c] -= 1
            if len(collections.Counter(c for c in cnt.itervalues() if c)) == 1:
                return True
            cnt[c] += 1
        return False
