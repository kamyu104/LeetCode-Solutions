# Time:  O(n)
# Space: O(1)

# math
class Solution(object):
    def minimumOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(x%3 != 0 for x in nums)


# Time:  O(n)
# Space: O(1)
# math
class Solution2(object):
    def minimumOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(min(x%3, 3-x%3) for x in nums)
