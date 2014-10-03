# Time:  O(m * n)
# Space: O(n)
#
# Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
# 
# For example, given the following triangle
# [
#      [2],
#     [3,4],
#    [6,5,7],
#   [4,1,8,3]
# ]
# The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
# 
# Note:
# Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
#

class Solution:
    # @param triangle, a list of lists of integers
    # @return an integer
    def minimumTotal(self, triangle):
        if len(triangle) == 0:
            return 0
        
        cur = triangle[0] + [float("inf")]
        for i in xrange(1, len(triangle)):
            next = []
            next.append(triangle[i][0] + cur[0])
            for j in xrange(1, i + 1):
                next.append(triangle[i][j] + min(cur[j - 1], cur[j]))
            cur = next + [float("inf")]
            
        return reduce(min, cur)

if __name__ == "__main__":
    print Solution().minimumTotal([[-1], [2, 3], [1, -1, -3]])
        