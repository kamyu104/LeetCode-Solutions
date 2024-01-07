# Time:  O(n)
# Space: O(n)

# math, hash table
class Solution(object):
    def maximumSetSize(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        lookup1, lookup2 = set(nums1), set(nums2)
        n, c = len(nums1), len(lookup1&lookup2)
        return min(min(len(lookup1)-c, n//2)+min(len(lookup2)-c, n//2)+c, n)


# Time:  O(n)
# Space: O(n)
# math, hash table
class Solution2(object):
    def maximumSetSize(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        lookup1, lookup2 = set(nums1), set(nums2)
        n, c = len(nums1), len(lookup1&lookup2)
        r1 = max(n//2-(len(lookup1)-c), 0)
        r2 = max(n//2-(len(lookup2)-c), 0)
        return min(len(lookup1)-c, n//2)+min(len(lookup2)-c, n//2)+min(r1+r2, c)
