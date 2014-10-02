# Time:  O(n)
# Space: O(1)
#
# Given n non-negative integers representing an elevation map where the width of each bar is 1,
#  compute how much water it is able to trap after raining.
# 
# For example, 
# Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
# 
# The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
# In this case, 6 units of rain water (blue section) are being trapped.
#

class Solution:
    # @param A, a list of integers
    # @return an integer
    def trap(self, A):
        result = 0
        top = 0
        for i in xrange(len(A)):
            if A[top] < A[i]:
                top = i
        
        second_top = 0
        for i in xrange(top):
            if A[second_top] < A[i]:
                second_top = i
            result += A[second_top] - A[i]
            
        second_top = len(A) - 1
        for i in reversed(xrange(top, len(A))):
            if A[second_top] < A[i]:
                second_top = i
            result += A[second_top] - A[i]
            
        return result
            
# Time:  O(n)
# Space: O(n)
class Solution2:
    # @param A, a list of integers
    # @return an integer
    def trap(self, A):
        result = 0
        stack = []
        
        for i in xrange(len(A)):
            mid_height = 0
            while stack:
                [pos, height] = stack.pop()
                result += (min(height, A[i]) - mid_height) * (i - pos - 1)
                mid_height = height
                
                if A[i] < height:
                    stack.append([pos, height])
                    break
            stack.append([i, A[i]])
            
        return result
    
if __name__ == "__main__":
    print Solution().trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1])