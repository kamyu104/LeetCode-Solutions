# Time:  O(n)
# Space: O(1)

class Solution(object):
    def getSumAbsoluteDifferences(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        prefix, suffix = 0, sum(nums)
        result = []
        for i, num in enumerate(nums):
            suffix -= num
            result.append((i*num-prefix) + (suffix-((len(nums)-1)-i)*num))
            prefix += num
        return result
