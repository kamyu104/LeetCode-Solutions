# Time:  O(n)
# Space: O(1)

class Solution(object):
    def minElements(self, nums, limit, goal):
        """
        :type nums: List[int]
        :type limit: int
        :type goal: int
        :rtype: int
        """
        return (abs(sum(nums)-goal) + (limit-1))//limit
