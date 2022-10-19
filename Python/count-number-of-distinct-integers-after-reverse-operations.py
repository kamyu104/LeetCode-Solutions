# Time:  O(nlogn)
# Space: O(n)

# hash table   
class Solution(object):
    def countDistinctIntegers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return len({y for x in nums for y in (x, int(str(x)[::-1]))})
