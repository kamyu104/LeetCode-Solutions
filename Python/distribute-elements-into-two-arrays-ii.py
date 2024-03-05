# Time:  O(nlogn)
# Space: O(n)

from sortedcontainers import SortedList


# sorted list
class Solution(object):
    def resultArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        sl1, sl2 = SortedList([nums[0]]), SortedList([nums[1]])
        a, b = [nums[0]], [nums[1]]
        for i in xrange(2, len(nums)):
            cnt1 = len(sl1)-sl1.bisect_right(nums[i])
            cnt2 = len(sl2)-sl2.bisect_right(nums[i])
            if cnt1 > cnt2 or (cnt1 == cnt2 and len(a) <= len(b)):
                sl1.add(nums[i])
                a.append(nums[i])
            else:
                sl2.add(nums[i])
                b.append(nums[i])
        return a+b
