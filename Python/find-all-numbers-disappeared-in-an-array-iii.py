# Time:  O(nlogn)
# Space: O(1)

# sort
class Solution(object):
    def findDisappearedNumbers(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: List[List[int]]
        """
        result = []
        nums.sort()
        for x in nums:
            if x < lower:
                continue
            if x > upper:
                break
            if lower <= x-1:
                result.append([lower, x-1])
            lower = x+1
        if lower <= upper:
            result.append([lower, upper])
        return result
