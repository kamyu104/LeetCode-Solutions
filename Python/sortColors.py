# Time:  O(n)
# Space: O(1)
#
# Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, 
# with the colors in the order red, white and blue.
# 
# Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
# 
# Note:
# You are not suppose to use the library's sort function for this problem.
# 
# click to show follow up.
# 
# Follow up:
# A rather straight forward solution is a two-pass algorithm using counting sort.
# First, iterate the array counting number of 0's, 1's, and 2's, 
# then overwrite array with total number of 0's, then 1's and followed by 2's.
# 
# Could you come up with an one-pass algorithm using only constant space?
#

class Solution:
    # @param A a list of integers
    # @return nothing, sort in place
    def sortColors(self, A):
        i, last_zero, first_two = 0, -1, len(A)
        
        while i < first_two:
            if A[i] == 0:
                last_zero += 1
                A[last_zero], A[i] = A[i], A[last_zero]
            elif A[i] == 2:
                first_two -= 1
                A[first_two], A[i] = A[i], A[first_two]
                i -= 1
            i += 1

if __name__ == "__main__":
    A = [2, 1, 1, 0, 0, 2]
    Solution().sortColors(A)
    print A