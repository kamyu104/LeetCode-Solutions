# Time:  O(n^2)
# Space: O(n)

# Given a 2D binary matrix filled with 0's and 1's, 
# find the largest rectangle containing all ones and return its area.

# Ascending stack solution.
class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        def largestRectangleArea(heights):
            increasing, area, i = [], 0, 0
            while i <= len(heights):
                if not increasing or (i < len(heights) and heights[i] > heights[increasing[-1]]):
                    increasing.append(i)
                    i += 1
                else:
                    last = increasing.pop()
                    if not increasing:
                        area = max(area, heights[last] * i)
                    else:
                        area = max(area, heights[last] * (i - increasing[-1] - 1 ))
            return area

        if not matrix:
            return 0

        result = 0
        heights = [0] * len(matrix[0])
        for i in xrange(len(matrix)):
            for j in xrange(len(matrix[0])):
                heights[j] = heights[j] + 1 if matrix[i][j] == '1' else 0
            result = max(result, largestRectangleArea(heights))

        return result


# Time:  O(n^2)
# Space: O(n)
# DP solution.
class Solution2(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if not matrix:
            return 0
        
        result = 0
        m = len(matrix)
        n = len(matrix[0])
        L = [0 for _ in xrange(n)]
        H = [0 for _ in xrange(n)]
        R = [n for _ in xrange(n)]

        for i in xrange(m):
            left = 0
            for j in xrange(n):
                if matrix[i][j] == '1':
                    L[j] = max(L[j], left)
                    H[j] += 1
                else:
                    L[j] = 0
                    H[j] = 0
                    R[j] = n
                    left = j + 1
                    
            right = n
            for j in reversed(xrange(n)):
                if matrix[i][j] == '1':
                    R[j] = min(R[j], right)
                    result = max(result, H[j] * (R[j] - L[j]))
                else:
                    right = j
                    
        return result

if __name__ == "__main__":
    matrix = ["01101",
              "11010",
              "01110",
              "11110",
              "11111",
              "00000"]
    print Solution().maximalRectangle(matrix)
