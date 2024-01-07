# Time:  O(n)
# Space: O(n)

# math, hash table, greedy
class Solution(object):
    def maximumSetSize(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        lookup1, lookup2 = set(nums1), set(nums2)
        n, c = len(nums1), len(lookup1&lookup2)
        d1, d2 = min(len(lookup1)-c, n//2), min(len(lookup2)-c, n//2)
        return min(n, d1+d2+c)


# Time:  O(n)
# Space: O(n)
# math, hash table, greedy
class Solution2(object):
    def maximumSetSize(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        lookup1, lookup2 = set(nums1), set(nums2)
        n, c = len(nums1), len(lookup1&lookup2)
        d1, d2 = min(len(lookup1)-c, n//2), min(len(lookup2)-c, n//2)
        r1, r2 = n//2-d1, n//2-d2
        return d1+d2+min(r1+r2, c)  # = min(d1+d2+r1+r2, d1+d2+c) = min(d1+d2+(n//2-d1)+(n//2-d2), d1+d2+c) = min(n, d1+d2+c)
