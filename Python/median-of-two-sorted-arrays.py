from __future__ import print_function
# Time:  O(log(min(m, n)))
# Space: O(1)

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

class Solution_3(object):
    def findMedianSortedArrays(self, A, B):

        if A is None and B is None:
            return -1.0
        lenA = len(A)
        lenB = len(B)
        lenn = lenA + lenB;

        indexA,indexB,indexC = 0,0,0
        C = [False for i in xrange(lenn)]
        while indexA < lenA and indexB < lenB:
            if A[indexA] < B[indexB]:
                C[indexC] = A[indexA]
                indexC += 1
                indexA += 1
            else:
                C[indexC] = B[indexB]
                indexC += 1
                indexB += 1

        while indexA < lenA:
            C[indexC] = A[indexA]
            indexC += 1
            indexA += 1

        while indexB < lenB:
            C[indexC] = B[indexB]
            indexC += 1
            indexB += 1

        indexM1 = (lenn - 1) / 2
        indexM2 = lenn / 2

        if (lenn % 2 == 0):
            return (C[indexM1] + C[indexM2]) / 2.0
        else:
            return C[indexM2] / 1.0

if __name__ == "__main__":
    print(Solution().findMedianSortedArrays([1, 3, 5, 7], [2, 4, 6]))
    print(Solution_Generic().findMedianSortedArrays([1, 3, 5], [2, 4, 6]))
    print(Solution_3().findMedianSortedArrays([1, 3, 5], [2, 4, 6]))

