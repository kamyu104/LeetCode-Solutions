# Time:  O(n)
# Space: O(n)

# hash table
class Solution(object):
    def duplicateNumbersXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return reduce(lambda x, y: x^y, nums, 0)^reduce(lambda x, y: x^y, set(nums), 0)


# Time:  O(n)
# Space: O(n)
import collections


# freq table
class Solution2(object):
    def duplicateNumbersXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return reduce(lambda x, y: x^y, (x for x, c in collections.Counter(nums).iteritems() if c == 2), 0)

