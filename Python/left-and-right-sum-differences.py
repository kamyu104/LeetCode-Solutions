# Time:  O(n)
# Space: O(1)

# prefix sum
class Solution(object):
    def leftRigthDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        total = sum(nums)
        result = []
        curr = 0
        for x in nums:
            curr += x
            result.append(abs((curr-x)-(total-curr)))
        return result
