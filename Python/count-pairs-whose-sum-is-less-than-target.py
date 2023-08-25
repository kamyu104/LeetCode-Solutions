# Time:  O(nlogn)
# Space: O(1)

# sort, two pointers
class Solution(object):
    def countPairs(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        result = 0
        left, right = 0, len(nums)-1
        while left < right:
            if nums[left]+nums[right] < target:
                result += right-left
                left += 1
            else:
                right -= 1
        return result
