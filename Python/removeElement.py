# Time:  O(n)
# Space: O(1)
#
# Given an array and a value, remove all instances of that value in place and return the new length.
# 
# The order of elements can be changed. It doesn't matter what you leave beyond the new length.
#

class Solution:
    # @param    A       a list of integers
    # @param    elem    an integer, value need to be removed
    # @return an integer
    def removeElement(self, A, elem):
        i, last = 0, len(A) - 1
        while i <= last:
            if A[i] == elem:
                A[i], A[last] = A[last], A[i]
                last -= 1
            else:
                i += 1
        return last + 1
    
if __name__ == "__main__":
    print Solution().removeElement([1, 2, 3, 4, 5, 2, 2], 2)