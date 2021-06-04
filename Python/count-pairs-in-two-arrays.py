# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def countPairs(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        for i in xrange(len(nums1)):
            nums1[i] -= nums2[i]
        nums1.sort()
        result = 0
        left, right = 0, len(nums1)-1
        while left < right:
            if nums1[left] > 0 or -nums1[left] < nums1[right]:
                result += right-left
                right -= 1
            else:
                left += 1
        return result
