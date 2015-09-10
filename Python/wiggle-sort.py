# Time:  O(n)
# Space: O(1)

class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        for i in xrange(1, len(nums)):
            if ((i & 1) and nums[i - 1] > nums[i]) or \
                (not (i & 1) and nums[i - 1] < nums[i]):
                nums[i - 1], nums[i] = nums[i], nums[i - 1]

class Solution2(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if not nums:
            return

        pre = nums[0]
        inc = True
        for i in xrange(1, len(nums)):
            if (inc and pre <= nums[i]) or \
                (not inc and pre >= nums[i]):
                nums[i - 1] = pre
                pre = nums[i]
            else:
                nums[i - 1] = nums[i]
            inc = not inc
        nums[-1] = pre
