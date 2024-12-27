# Time:  O(n^2)
# Space: O(1)

# brute force
class Solution(object):
    def maximumMatchingIndices(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        return max(sum(nums2[j] == nums1[(i+j)%len(nums1)] for j in xrange(len(nums2))) for i in xrange(len(nums1)))
