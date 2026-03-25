# Time:  O(n)
# Space: O(1)

# constructive algorithms
class Solution(object):
    def uniformArray(self, nums1):
        """
        :type nums1: List[int]
        :rtype: bool
        """
        return min(nums1)%2 == 1 or all(x%2 == 0 for x in nums1)
