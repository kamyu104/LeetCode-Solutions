# Time:  O(logn)
# Space: O(1)

# math
class Solution(object):
    def maxHeightOfTriangle(self, red, blue):
        """
        :type red: int
        :type blue: int
        :rtype: int
        """
        def f(x, y):
            # odd level:
            # (1+h)*((1+h)//2)//2 <= x
            # => h <= int(2*x**0.5)-1
            # even level:
            # (2+h)*(h//2)//2 <= y
            # => h <= int((4*y+1)**0.5)-1
            a, b = int(2*x**0.5)-1, int((4*y+1)**0.5)-1
            return min(a, b)+int(a != b)
        
        return max(f(red, blue), f(blue, red))


# Time:  O(sqrt(n))
# Space: O(1)
# simulation
class Solution2(object):
    def maxHeightOfTriangle(self, red, blue):
        """
        :type red: int
        :type blue: int
        :rtype: int
        """
        def f(x, y):
            h = 0
            while x >= h+1:
                h += 1
                x -= h
                x, y = y, x
            return h

        return max(f(red, blue), f(blue, red))
