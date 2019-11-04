# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def maxNumberOfBalloons(self, text):
        """
        :type text: str
        :rtype: int
        """
        TARGET = "balloon"
        source_count = collections.Counter(text)
        target_count = collections.Counter(TARGET)
        return min(source_count[c]//target_count[c] for c in target_count.iterkeys())
