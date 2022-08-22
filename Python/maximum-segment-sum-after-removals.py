# Time:  O(nlogn)
# Space: O(n)

from sortedcontainers import SortedList


# prefix sum, sorted list
class Solution(object):
    def maximumSegmentSum(self, nums, removeQueries):
        """
        :type nums: List[int]
        :type removeQueries: List[int]
        :rtype: List[int]
        """
        removed_idxs = SortedList([-1, len(nums)])
        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix[i+1] = prefix[i]+nums[i]
        segments = SortedList([prefix[-1]])
        result = []
        for q in removeQueries: 
            removed_idxs.add(q)
            i = removed_idxs.bisect_left(q)
            left, right = removed_idxs[i-1], removed_idxs[i+1]
            segments.remove(prefix[right]-prefix[left+1])
            segments.add(prefix[q]-prefix[left+1])
            segments.add(prefix[right]-prefix[q+1])
            result.append(segments[-1])
        return result
