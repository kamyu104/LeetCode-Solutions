# Time:  O(log(min(m, n)))
# Space: O(1)
 
# There are two sorted arrays nums1 and nums2 of size m and n respectively.
# Find the median of the two sorted arrays.
# The overall run time complexity should be O(log (m+n)).

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        len1, len2 = len(nums1), len(nums2)
        if (len1 + len2) % 2 == 1: 
            return self.getKth(nums1, nums2, (len1 + len2)/2 + 1)
        else:
            return (self.getKth(nums1, nums2, (len1 + len2)/2) + \
                    self.getKth(nums1, nums2, (len1 + len2)/2 + 1)) * 0.5

    def getKth(self, A, B, k):
        m, n = len(A), len(B)
        if m > n:
            return self.getKth(B, A, k)

        left, right = 0, m    
        while left < right:
            mid = left + (right - left) / 2
            if 0 <= k - 1 - mid < n and A[mid] >= B[k - 1 - mid]:
                right = mid
            else:
                left = mid + 1

        Ai_minus_1 = A[left - 1] if left - 1 >= 0 else float("-inf")
        Bj = B[k - 1 - left] if k - 1 - left >= 0 else float("-inf")

        return max(Ai_minus_1, Bj)


# Time:  O(log(max(m, n)) * log(max_val - min_val))
# Space: O(1)
# Generic solution.
class Solution_Generic(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        len1, len2 = len(nums1), len(nums2)
        if (len1 + len2) % 2 == 1: 
            return self.getKth([nums1, nums2], (len1 + len2)/2 + 1)
        else:
            return (self.getKth([nums1, nums2], (len1 + len2)/2) + \
                    self.getKth([nums1, nums2], (len1 + len2)/2 + 1)) * 0.5

    def getKth(self, arrays, k):
        def binary_search(array, left, right, target, compare):
            while left <= right:
                mid = left + (right - left) / 2
                if compare(array, mid, target):
                    right = mid - 1
                else:
                    left = mid + 1
            return left

        def match(arrays, num, target):
            res = 0
            for array in arrays:
                if array:
                    res += len(array) - binary_search(array, 0, len(array) - 1, num, \
                                                      lambda array, x, y: array[x] > y)
            return res < target

        left, right = float("inf"), float("-inf")
        for array in arrays:
            if array:
                left = min(left, array[0])
                right = max(right, array[-1])

        return binary_search(arrays, left, right, k, match)


if __name__ == "__main__":
    print Solution().findMedianSortedArrays([1, 3, 5, 7], [2, 4, 6])
    print Solution().findMedianSortedArrays([1, 3, 5], [2, 4, 6])
 
