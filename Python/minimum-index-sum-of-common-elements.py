# Time:  O(n + m)
# Space: O(n)

# hash table
class Solution(object):
    def minimumSum(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        INF = float("inf")
        lookup = {}
        for i, x in enumerate(nums1):
            if x in lookup:
                continue
            lookup[x] = i
        result = INF
        for j, x in enumerate(nums2):
            if x in lookup:
                result = min(result, lookup[x]+j)
        return result if result != INF else -1
