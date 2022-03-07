# Time:  O(n)
# Space: O(n)

import collections


# freq table
class Solution(object):
    def mostFrequent(self, nums, key):
        """
        :type nums: List[int]
        :type key: int
        :rtype: int
        """
        return collections.Counter(nums[i+1] for i in xrange(len(nums)-1) if nums[i] == key).most_common(1)[0][0]
