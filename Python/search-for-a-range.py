# Time:  O(logn)
# Space: O(1)
#
# Given a sorted array of integers, find the starting and ending position of a given target value.
# 
# Your algorithm's runtime complexity must be in the order of O(log n).
# 
# If the target is not found in the array, return [-1, -1].
# 
# For example,
# Given [5, 7, 7, 8, 8, 10] and target value 8,
# return [3, 4].
#

class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return a list of length 2, [index1, index2]
    def searchRange(self, A, target):
        # Find the first index where target <= A[idx]
        left = self.binarySearch(lambda x, y: x <= y, A, target)
        if left >= len(A) or A[left] != target:
            return [-1, -1]
        # Find the first index where target < A[idx]
        right = self.binarySearch(lambda x, y: x < y, A, target)
        return [left, right - 1]
    
    def binarySearch(self, compare, A, target):
        start, end = 0, len(A)
        while start < end:
            mid = start + (end - start) / 2
            if compare(target, A[mid]):
                end = mid
            else:
                start = mid + 1
        return start
    
    def binarySearch2(self, compare, A, target):
        start, end = 0, len(A) - 1
        while start <= end:
            mid = start + (end - start) / 2
            if compare(target, A[mid]):
                end = mid - 1
            else:
                start = mid + 1
        return start

if __name__ == "__main__":
    print Solution().searchRange([2, 2], 3)
    print Solution().searchRange([5, 7, 7, 8, 8, 10], 8)
