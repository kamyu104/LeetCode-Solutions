# Time:  O(m * n)
# Space: O(1)

import itertools


class Solution(object):
    def maximumWealth(self, accounts):
        """
        :type accounts: List[List[int]]
        :rtype: int
        """
        return max(itertools.imap(sum, accounts))
