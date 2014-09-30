# Time:  O(logn)
# Space: O(1)
#
# Suppose a sorted array is rotated at some pivot unknown to you beforehand.
# 
# (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
# 
# You are given a target value to search. If found in the array return its index, otherwise return -1.
# 
# You may assume no duplicate exists in the array.
#

class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return an integer
    def search(self, A, target):
        low, high = 0, len(A)
        
        while low < high:
            mid = low + (high - low) / 2
            
            if A[mid] == target:
                return mid
            
            if A[low] <= A[mid]:
                if A[low] <= target and target < A[mid]:
                    high = mid
                else:
                    low = mid + 1
            else:
                if A[mid] < target and target <= A[high - 1]:
                    low = mid + 1
                else:
                    high = mid
                    
        return -1
        

if __name__ == "__main__":
    print Solution().search([3, 5, 1], 3)
    print Solution().search([1], 1)
    print Solution().search([4, 5, 6, 7, 0, 1, 2], 5)