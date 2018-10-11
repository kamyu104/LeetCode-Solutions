# Time:  O(n)
# Space: O(1)

class Solution(object):
    def arrayNesting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for num in nums:
            if num is not None:
                start, count = num, 0
                while nums[start] is not None:
                    temp = start
                    start = nums[start]
                    nums[temp] = None
                    count += 1
                result = max(result, count)
        return result

