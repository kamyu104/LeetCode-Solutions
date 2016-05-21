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


# If the given array is already sorted, and m << n
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

        nums1.sort(), nums2.sort()  # Make sure it is sorted.

        cnts = collections.defaultdict(int)
        for i in nums1:
            cnt = count_of_num(nums2, i)
            if cnt > 0 and cnts[i] < cnt:
                cnts[i] += 1
        res = []
        for k, v in cnts.iteritems():
            res += [k] * v
        
        return res

# If the given array is already sorted, and memory is limited or m ~ n
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
