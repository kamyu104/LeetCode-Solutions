# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        result, max_count = 0, 0
        count = collections.Counter()
        for i in xrange(len(s)):
            count[s[i]] += 1
            max_count = max(max_count, count[s[i]])
            if result - max_count >= k:
                count[s[i-result]] -= 1
            else:
                result += 1
        return result

