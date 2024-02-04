# Time:  O(n)
# Space: O(1)

# prefix sum
class Solution(object):
    def returnToBoundaryCount(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = curr = 0
        for x in nums:
            curr += x
            if curr == 0:
                result += 1
        return result
