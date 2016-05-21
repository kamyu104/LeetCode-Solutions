# If the given array is not sorted and the memory is unlimited.
# Time:  O(m + n)
# Space: O(min(m, n))
# Hash solution.
class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        if len(nums1) > len(nums2):
            return self.intersect(nums2, nums1)
  
        lookup = collections.defaultdict(int)
        for n in nums1:
            lookup[n] += 1

        res = []
        for n in nums2:
            if lookup[n] > 0:
                res += n,
                lookup[n] -= 1

        return res


# If the given array is already sorted, and memory is limited, and m ~ n:
# Time:  O(m + n)
# Soace: O(1)
# Two pointer solution.
class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums1.sort(), nums2.sort()  # Make sure it is sorted.

        res = []
        
        it1, it2 = 0, 0
        while it1 < len(nums1) and it2 < len(nums2):
            if nums1[it1] < nums2[it2]:
                it1 += 1
            elif nums1[it1] > nums2[it2]:
                it2 += 1
            else:
                res += nums1[it1],
                it1 += 1
                it2 += 1
        
        return res


# If the given array is already sorted, and momory is limited, and m << n
# Time:  O(mlogn)
# Space: O(1)
