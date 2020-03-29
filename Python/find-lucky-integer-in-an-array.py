# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def findLucky(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        count = collections.Counter(arr)
        result = -1
        for k, v in count.iteritems():
            if k == v:
                result = max(result, k)
        return result
