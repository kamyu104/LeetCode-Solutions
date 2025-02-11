# Time:  O(n)
# Space: O(n)

import collections


# hash table, unordered set
class Solution(object):
    def maxStudentsOnBench(self, students):
        """
        :type students: List[List[int]]
        :rtype: int
        """
        lookup = collections.defaultdict(set)
        for s, b in students:
            lookup[b].add(s)
        return max(len(x) for x in lookup.itervalues()) if lookup else 0
