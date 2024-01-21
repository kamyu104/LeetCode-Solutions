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
        sl = SortedList(nums[1:1+(1+dist)])
        curr = mn = sum(sl[:k-1])
        for i in xrange(1+(1+dist), len(nums)):
            sl.add(nums[i])
            curr += min(nums[i]-sl[k-1], 0)
            curr -= min(nums[i-(1+dist)]-sl[k-1], 0)
            sl.remove(nums[i-(1+dist)])
            mn = min(mn, curr)
        return nums[0]+mn


# Time:  O(nlogd)
# Space: O(d)
from sortedcontainers import SortedList


# sliding window, sorted list
class Solution2(object):
    def minimumCost(self, nums, k, dist):
        """
        :type nums: List[int]
        :type k: int
        :type dist: int
        :rtype: int
        """
        sl1, sl2 = SortedList(), SortedList()
        curr, mn = 0, float("inf")
        for i in xrange(1, len(nums)):
            sl1.add(nums[i])
            curr += nums[i]
            if len(sl1) > k-1:
                curr -= sl1[-1]
                sl2.add(sl1.pop())
            if len(sl1)+len(sl2) > 1+dist:
                if sl2[0] <= nums[i-(1+dist)]:
                    sl2.remove(nums[i-(1+dist)])
                else:
                    sl1.remove(nums[i-(1+dist)])
                    curr -= nums[i-(1+dist)]-sl2[0]
                    sl1.add(sl2.pop(0))
            if len(sl1) == k-1:
                mn = min(mn, curr)
        return nums[0]+mn
