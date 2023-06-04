# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def semiOrderedPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i, j = nums.index(1), nums.index(len(nums))
        return i+((len(nums)-1)-j)-int(i > j)
