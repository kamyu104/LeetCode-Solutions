# Time:  O(n)
# Space: O(n)

import collections


# hash table
class Solution(object):
    def countSpecialIntegers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        lookup = collections.defaultdict(list)
        for i, x in enumerate(nums):
            lookup[x].append(i)
        return sum(len(idxs) == 3 and all(idxs[i+1]-idxs[i] == idxs[-1]-idxs[-2] for i in xrange(len(idxs)-2)) for idxs in lookup.itervalues())
