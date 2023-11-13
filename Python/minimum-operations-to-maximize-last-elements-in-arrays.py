# Time:  O(n)
# Space: O(1)

# simulation
class Solution(object):
    def minOperations(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        INF = float("inf")
        def count(mx1, mx2):
            return sum(1 if nums2[i] <= mx1 and nums1[i] <= mx2 else INF for i in xrange(len(nums1)-1) if not (nums1[i] <= mx1 and nums2[i] <= mx2))

        result = min(count(nums1[-1], nums2[-1]), count(nums2[-1], nums1[-1])+1)
        return result if result != INF else -1
