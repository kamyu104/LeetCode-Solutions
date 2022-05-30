# Time:  O(n)
# Space: O(1)

import collections


# freq table
class Solution(object):
    def digitCount(self, num):
        """
        :type num: str
        :rtype: bool
        """
        cnt = collections.Counter(num)
        return all(cnt[str(i)] == int(x) for i, x in enumerate(num))
