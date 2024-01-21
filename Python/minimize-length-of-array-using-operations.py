# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def minimumArrayLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mn = min(nums)
        return (nums.count(mn)+1)//2 if all(x%mn == 0 for x in nums) else 1
