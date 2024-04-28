# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def addedInteger(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        return max(nums2)-max(nums1)
