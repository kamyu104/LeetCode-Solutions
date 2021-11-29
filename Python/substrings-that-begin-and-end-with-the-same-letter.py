# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def numberOfSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        cnt = collections.Counter()
        for c in s:
            cnt[c] += 1
            result += cnt[c]
        return result


# Time:  O(n)
# Space: O(1)
import collections


class Solution(object):
    def numberOfSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        return sum(v*(v+1)//2 for v in collections.Counter(s).itervalues())
