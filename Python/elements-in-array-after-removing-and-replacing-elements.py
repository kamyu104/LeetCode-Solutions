# Time:  O(n)
# Space: O(1)

class Solution(object):
    def elementInNums(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        result = []
        for t, i in queries:
            t %= 2*len(nums)
            if t+i < len(nums):
                result.append(nums[t+i])
            elif i < t-len(nums):
                result.append(nums[i])
            else:
                result.append(-1)
        return result
