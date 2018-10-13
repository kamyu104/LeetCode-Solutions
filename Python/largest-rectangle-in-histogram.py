# Time:  O(n)
# Space: O(n)

class Solution(object):
    # @param height, a list of integer
    # @return an integer
    def largestRectangleArea(self, height):
        increasing, area, i = [], 0, 0
        while i <= len(height):
            if not increasing or (i < len(height) and height[i] > height[increasing[-1]]):
                increasing.append(i)
                i += 1
            else:
                last = increasing.pop()
                if not increasing:
                    area = max(area, height[last] * i)
                else:
                    area = max(area, height[last] * (i - increasing[-1] - 1 ))
        return area

