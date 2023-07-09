# Time:  O(nlogn)
# Space: O(n)

import itertools


# hash table, sort
class Solution(object):
    def relocateMarbles(self, nums, moveFrom, moveTo):
        """
        :type nums: List[int]
        :type moveFrom: List[int]
        :type moveTo: List[int]
        :rtype: List[int]
        """
        lookup = set(nums)
        for a, b in itertools.izip(moveFrom, moveTo):
            lookup.remove(a)
            lookup.add(b)
        return sorted(lookup)
