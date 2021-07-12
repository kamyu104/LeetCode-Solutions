# Time:  O(n)
# Space: O(1)

class Solution(object):
    def getConcatenation(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums.extend(nums)
        return nums


# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def getConcatenation(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return nums+nums


# Time:  O(n)
# Space: O(1)
class Solution3(object):
    def getConcatenation(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return nums*2
