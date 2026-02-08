# Time:  O(n)
# Space: O(1)

# stack, simulation
class Solution(object):
    def mergeAdjacent(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result = []
        for x in nums:
            while result and result[-1] == x:
                result.pop()
                x *= 2
            result.append(x)
        return result
