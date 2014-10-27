# Time:  O(n)
# Space: O(1)
#
# Given n non-negative integers a1, a2, ..., an, 
# where each represents a point at coordinate (i, ai). 
# n vertical lines are drawn such that the two endpoints of 
# line i is at (i, ai) and (i, 0). Find two lines, 
# which together with x-axis forms a container, 
# such that the container contains the most water.
# 
# Note: You may not slant the container.
#

class Solution:
    # @return an integer
    def maxArea(self, height):
        max_area, i, j = 0, 0, len(height) - 1
        while i < j:
            max_area = max(max_area, min(height[i], height[j]) * (j - i))
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        return max_area
    
if __name__ == "__main__":
    height = [1, 2, 3, 4, 3, 2, 1, 5]
    result = Solution().maxArea(height)
    print result