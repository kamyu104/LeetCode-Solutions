# Time:  O(n)
# Space: O(n)

# two pointers
class Solution(object):
    def pivotArray(self, nums, pivot):
        """
        :type nums: List[int]
        :type pivot: int
        :rtype: List[int]
        """
        result = [pivot]*len(nums)
        left, right = 0, len(nums)-sum(x > pivot for x in nums)
        for x in nums:
            if x < pivot:
                result[left] = x
                left += 1
            elif x > pivot:
                result[right] = x
                right += 1
        return result
