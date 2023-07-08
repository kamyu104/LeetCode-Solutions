# Time:  O(n)
# Space: O(n)

import collections


# mono deque, two pointers
class Solution(object):
    def continuousSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mn, mx = collections.deque(), collections.deque()
        result = left = 0
        for right in xrange(len(nums)):
            while mn and nums[mn[-1]] > nums[right]:
                mn.pop()
            mn.append(right)
            while mx and nums[mx[-1]] < nums[right]:
                mx.pop()
            mx.append(right)
            while not nums[mx[0]]-nums[mn[0]] <= 2:
                if mn[0] < mx[0]:
                    mn.popleft()
                else:
                    mx.popleft()
                left = max(left, min(mn[0], mx[0]))
            result += right-left+1
        return result


# Time:  O(nlogn)
# Space: O(n)
from sortedcontainers import SortedDict


# ordered dict, two pointers
class Solution2(object):
    def continuousSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = left = 0;
        lookup = SortedDict()
        for right in xrange(len(nums)):
            lookup[nums[right]] = right
            to_del = []
            for x, i in lookup.items():
                if nums[right]-x <= 2:
                    break
                left = max(left, i+1)
                to_del.append(x)
            for x, i in reversed(lookup.items()):
                if x-nums[right] <= 2:
                    break
                left = max(left, i+1)
                to_del.append(x) 
            for x in to_del:
                del lookup[x]
            result += right-left+1;
        return result;
