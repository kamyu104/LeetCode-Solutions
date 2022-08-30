# Time:  O(nlogn + qlogn)
# Space: O(1)

import bisect


# greedy, sort, binary search
class Solution(object):
    def answerQueries(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[int]
        :rtype: List[int]
        """
        nums.sort()
        for i in xrange(len(nums)-1):
            nums[i+1] += nums[i]
        return [bisect.bisect_right(nums, q) for q in queries]
