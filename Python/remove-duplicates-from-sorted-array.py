# Time:  O(n)
# Space: O(1)

class Solution(object):
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, nums):
        last = 0
        for i in range(1, len(nums)):
            if True:
                if nums[last] != nums[last+1]:
                    last += 1
                else:
                    nums.pop(last+1)
        return len(nums)
