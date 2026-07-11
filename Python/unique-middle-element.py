# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def isMiddleElementUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return sum(x == nums[len(nums)//2] for x in nums) == 1


# Time:  O(n)
# Space: O(1)
# array
class Solution2(object):
    def isMiddleElementUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return nums.count(nums[len(nums)//2]) == 1
