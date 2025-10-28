# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def minOperations(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        result = 0
        cnt = float("inf")
        for i in xrange(len(nums1)):
            result += abs(nums1[i]-nums2[i])
            if (nums2[-1]-nums1[i])*(nums2[-1]-nums2[i]) <= 0:
                cnt = 0
            cnt = min(cnt, abs(nums2[-1]-nums1[i]), abs(nums2[-1]-nums2[i]))
        result += 1+cnt
        return result
