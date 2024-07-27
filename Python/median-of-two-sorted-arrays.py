# Time:  O(log(min(m, n)))
# Space: O(1)

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        def binary_search(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def getKth(A, B, k):
            m, n = len(A), len(B)
            if m > n:
                m, n = n, m
                A, B = B, A
            i = binary_search(max(k-n, 0), min(m, k)-1, lambda i: A[i] >= B[k-1-i])
            return max(A[i-1] if i-1 >= 0 else float("-inf"), B[k-1-i] if k-1-i >= 0 else float("-inf"))

        len1, len2 = len(nums1), len(nums2)
        if (len1+len2) % 2 == 1:
            return getKth(nums1, nums2, (len1+len2)//2+1)
        else:
            return (getKth(nums1, nums2, (len1+len2)//2)+getKth(nums1, nums2, (len1+len2)//2+1))*0.5    


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
        def binary_search(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def getKth(arrays, k):
            def check(num):
                # count the number of values which are less or equal to num
                return sum(binary_search(0, len(arr)-1, lambda x: arr[x] > num) for arr in arrays) >= k
    
            return binary_search(min(arr[0] for arr in arrays if arr), max(arr[-1] for arr in arrays if arr), check)

        array = [nums1, nums2]
        total = sum(len(nums) for nums in array)
        if total % 2 == 1:
            return getKth(array, total//2+1)
        else:
            return (getKth(array, total//2)+getKth(array, total//2+1))*0.5
