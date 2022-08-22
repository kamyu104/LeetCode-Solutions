# Time:  O(n)
# Space: O(1)

import collections


# freq table, greedy
class Solution(object):
    def largestPalindromic(self, num):
        """
        :type num: str
        :rtype: str
        """
        cnt = collections.Counter(num)
        result = []
        for i in reversed(xrange(10)):
            if not cnt[str(i)]//2 or (i == 0 and not result):
                continue
            for _ in xrange(cnt[str(i)]//2):
                result.append(str(i))
        result.append(max([k for k, v in cnt.iteritems() if v%2] or [""]))
        for i in reversed(xrange(len(result)-1)):
            result.append(result[i])
        return "".join(result) or "0"
