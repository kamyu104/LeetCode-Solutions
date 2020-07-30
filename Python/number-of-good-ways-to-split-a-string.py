# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def numSplits(self, s):
        """
        :type s: str
        :rtype: int
        """
        left_count, right_count = collections.Counter(), collections.Counter(s)
        result = 0
        for c in s:
            left_count[c] += 1
            right_count[c] -= 1
            if not right_count[c]:
                del right_count[c]
            if len(left_count) == len(right_count):
                result += 1
        return result
