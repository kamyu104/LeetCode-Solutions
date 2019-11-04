# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def longestSubsequence(self, arr, difference):
        """
        :type arr: List[int]
        :type difference: int
        :rtype: int
        """
        result = 1
        lookup = collections.defaultdict(int)
        for i in xrange(len(arr)):
            lookup[arr[i]] = lookup[arr[i]-difference] + 1
            result = max(result, lookup[arr[i]])
        return result
