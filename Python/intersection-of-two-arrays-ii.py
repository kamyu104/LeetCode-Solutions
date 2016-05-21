# If the given array is not sorted and the memory is unlimited:
#   - Time:  O(m + n)
#   - Space: O(min(m, n))
# elif the given array is already sorted:
#   if the memory is unlimited, and (m << n or m >> n)
#     - Time:  O(min(m, n) * log(max(m, n)))
#     - Space: O(min(m, n))
#   else:
#     - Time:  O(m + n)
#     - Soace: O(1)
# else: (the memory is limited)
#     - Time:  O(max(m, n) * log(max(m, n)))
#     - Space: O(max(m, n))

# Given two arrays, write a function to compute their intersection.
#
# Example:
# Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
#
# Note:
# Each element in the result should appear as many times as it shows in both arrays.
# The result can be in any order.
#
# Follow up:
# - What if the given array is already sorted? How would you optimize your algorithm?
# - What if nums1's size is small compared to num2's size? Which algorithm is better?
# - What if elements of nums2 are stored on disk, and the memory is limited such that
#   you cannot load all elements into the memory at once?


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
        for i in nums1:
            lookup[i] += 1

        res = []
        for i in nums2:
            if lookup[i] > 0:
                res += i,
                lookup[i] -= 1

        return res


# If the given array is already sorted, and the memory is unlimited, and (m << n or m >> n).
# Time:  O(min(m, n) * log(max(m, n)))
# Space: O(min(m, n))
# Binary search solution.
class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        if len(nums1) > len(nums2):
            return self.intersect(nums2, nums1)

        def count_of_num(nums, target):
            def binary_search(compare, nums, target):
                left, right = 0, len(nums)
                while left < right:
                    mid = left + (right - left) / 2
                    if compare(nums[mid], target):
                        right = mid
                    else:
                        left = mid + 1
                return left

            left = binary_search(lambda x, y: x >= y, nums, target)
            right = binary_search(lambda x, y: x > y, nums, target)
            return right - left

        nums1.sort(), nums2.sort()  # Make sure it is sorted, doesn't count in time.

        cnts = collections.defaultdict(int)
        for i in nums1:
            cnt = count_of_num(nums2, i)
            if cnts[i] < cnt:
                cnts[i] += 1

        res = []
        for k, v in cnts.iteritems():
            res += [k] * v
        
        return res


# If the given array is already sorted, and the memory is limited or m ~ n.
# Time:  O(m + n)
# Soace: O(1)
# Two pointers solution.
class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums1.sort(), nums2.sort()  # Make sure it is sorted, doesn't count in time.

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


# If the given array is not sorted, and the memory is limited.
# Time:  O(max(m, n) * log(max(m, n)))
# Space: O(max(m, n))
# Two pointers solution.
class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums1.sort(), nums2.sort()  # O(max(m, n) * log(max(m, n)))

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
