# Time:  O(n)
# Space: O(n)

# hash table
class Solution(object):
    def maxProductPair(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        result = [-1, -1]
        mx = float("-inf")
        lookup = {}
        for i, x in enumerate(nums):
            if target-x in lookup and x != target-x and x*(target-x) > mx:
                mx = x*(target-x)
                result[:] = [i, lookup[target-x]]
                if x < target-x:
                    result[0], result[1] = result[1], result[0]
            lookup[x] = i
        return result
