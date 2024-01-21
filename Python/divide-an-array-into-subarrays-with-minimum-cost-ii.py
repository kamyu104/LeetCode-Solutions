# Time:  O(nlogd)
# Space: O(d)

from sortedcontainers import SortedList


# sliding window, sorted list
class Solution(object):
    def minimumCost(self, nums, k, dist):
        """
        :type nums: List[int]
        :type k: int
        :type dist: int
        :rtype: int
        """
        sl = SortedList(nums[1:1+dist])
        curr, mn = sum(sl[:k-2]), float("inf")
        for i in xrange(1+dist, len(nums)):
            sl.add(nums[i])
            curr += min(nums[i], sl[k-2])
            mn = min(mn, curr)
            curr -= min(nums[i-dist], sl[k-2])
            sl.remove(nums[i-dist])
        return nums[0]+mn
