# Time:  O(nlogn)
# Space: O(n)

from sortedcontainers import SortedList


# sorted list, prefix sum
class Solution(object):
    def maximumTripletValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = SortedList()
        right = [0]*len(nums)
        for i in reversed(xrange(1, len(nums)-1)):
            right[i] = max(right[i+1], nums[i+1])
        result = 0
        for i in xrange(1, len(nums)-1):
            left.add(nums[i-1])
            j = left.bisect_left(nums[i])
            if j-1 >= 0 and right[i] > nums[i]:
                result = max(result, left[j-1]-nums[i]+right[i])
        return result


# Time:  O(nlogn)
# Space: O(n)
from sortedcontainers import SortedList


# sorted list
class Solution2(object):
    def maximumTripletValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = SortedList()
        right = SortedList(nums[i] for i in xrange(1, len(nums)))
        result = 0
        for i in xrange(1, len(nums)-1):
            left.add(nums[i-1])
            right.remove(nums[i])
            j = left.bisect_left(nums[i])
            if j-1 >= 0 and right[-1] > nums[i]:
                result = max(result, left[j-1]-nums[i]+right[-1])
        return result
