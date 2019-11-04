# Time:  O(n)
# Space: O(1)

"""
   This is the custom function interface.
   You should not implement it, or speculate about its implementation
   class CustomFunction:
       # Returns f(x, y) for any given positive integers x and y.
       # Note that f(x, y) is increasing with respect to both x and y.
       # i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
       def f(self, x, y):
  
"""
class Solution(object):
    def findSolution(self, customfunction, z):
        """
        :type num: int
        :type z: int
        :rtype: List[List[int]]
        """
        result = []
        x, y = 1, 1
        while customfunction.f(x, y) < z:
            y += 1
        while y > 0:
            while y > 0 and customfunction.f(x, y) > z:
                y -= 1
            if y > 0 and customfunction.f(x, y) == z:
                result.append([x, y])
            x += 1
        return result
