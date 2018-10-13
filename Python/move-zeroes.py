# Time:  O(n)
# Space: O(1)

class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        pos = 0
        for i in xrange(len(nums)):
            if nums[i]:
                nums[i], nums[pos] = nums[pos], nums[i]
                pos += 1

    def moveZeroes2(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        nums.sort(cmp=lambda a, b: 0 if b else -1)


class Solution2(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        pos = 0
        for i in xrange(len(nums)):
            if nums[i]:
                nums[pos] = nums[i]
                pos += 1

        for i in xrange(pos, len(nums)):
            nums[i] = 0


