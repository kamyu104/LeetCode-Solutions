# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def findingUsersActiveMinutes(self, logs, k):
        """
        :type logs: List[List[int]]
        :type k: int
        :rtype: List[int]
        """
        lookup = collections.defaultdict(set)
        for u, t in logs:
            lookup[u].add(t)
        result = [0]*k
        for _, ts in lookup.iteritems():
            result[len(ts)-1] += 1
        return result
