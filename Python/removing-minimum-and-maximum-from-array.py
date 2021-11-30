# Time:  O(n)
# Space: O(1)

class Solution(object):
    def minimumDeletions(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i, j = nums.index(min(nums)), nums.index(max(nums))
        if i > j:
            i, j = j, i
        return min((i+1)+(len(nums)-j), j+1, len(nums)-i)
