# Time:  O(n)
# Space: O(n)

import collections


# hash table
class Solution(object):
    def minimumSeconds(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        lookup = collections.defaultdict(int)
        dist = collections.defaultdict(int)
        for i in xrange(2*len(nums)):
            x = nums[i%len(nums)]
            dist[x] = max(dist[x], i-lookup[x])
            lookup[x] = i
        return min(dist.itervalues())//2
