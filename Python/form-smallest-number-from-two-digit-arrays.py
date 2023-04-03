# Time:  O(m + n)
# Space: O(m + n)

# hash table
class Solution(object):
    def minNumber(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        common = set(nums1)&set(nums2)
        if common:
            return min(common)
        mn1, mn2 = min(nums1), min(nums2)
        if mn1 > mn2:
            mn1, mn2 = mn2, mn1
        return 10*mn1+mn2
