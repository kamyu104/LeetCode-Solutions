# Time:  O(n + q)
# Space: O(n)

# array
class Solution(object):
    def occurrencesOfElement(self, nums, queries, x):
        """
        :type nums: List[int]
        :type queries: List[int]
        :type x: int
        :rtype: List[int]
        """
        lookup = [i for i, y in enumerate(nums) if y == x]
        return [lookup[q-1] if q-1 < len(lookup) else -1 for q in queries]
