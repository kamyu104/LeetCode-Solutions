# Time:  O(nlogn)
# Space: O(1)

import itertools


# greedy, sort
class Solution(object):
    def makeSimilar(self, nums, target):
        """
        :type nums: List[int]
        :type target: List[int]
        :rtype: int
        """
        nums.sort(key=lambda x: (x%2, x))
        target.sort(key=lambda x: (x%2, x))
        return sum(abs(x-y)//2 for x, y in itertools.izip(nums, target))//2
