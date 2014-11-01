# Time:  O(logn)
# Space: O(1)
#
# Follow up for "Search in Rotated Sorted Array":
# What if duplicates are allowed?
# 
# Would this affect the run-time complexity? How and why?
# 
# Write a function to determine if a given target is in the array.
#

class Solution:
    # @param A a list of integers
    # @param target an integer
    # @return a boolean
    def search(self, A, target):
        low, high = 0, len(A)
        
        while low < high:
            mid = low + (high - low) / 2
            
            if A[mid] == target:
                return True
            
            if A[low] < A[mid]:
                if A[low] <= target and target < A[mid]:
                    high = mid
                else:
                    low = mid + 1
            elif A[low] > A[mid]:
                if A[mid] < target and target <= A[high - 1]:
                    low = mid + 1
                else:
                    high = mid
            else:
                low += 1
                
        return False
        

if __name__ == "__main__":
    print Solution().search([3, 5, 1], 3)
    print Solution().search([2, 2, 3, 3, 4, 1], 1)
    print Solution().search([4, 4, 5, 6, 7, 0, 1, 2], 5)