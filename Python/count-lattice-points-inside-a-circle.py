# Time:  O(n * r^2)
# Space: O(min(n * r^2, (max_x-min_x)*(max_y-min_y))

# math, set
class Solution(object):
    def countLatticePoints(self, circles):
        """
        :type circles: List[List[int]]
        :rtype: int
        """
        lookup = set()
        for x, y, r in circles:
            for i in xrange(-r, r+1):
                for j in xrange(-r, r+1):
                    if i**2+j**2 <= r**2:
                        lookup.add(((x+i), (y+j)))
        return len(lookup)


# Time:  O(n * (max_x-min_x)*(max_y-min_y))
# Space: O(1)
# math
class Solution2(object):
    def countLatticePoints(self, circles):
        """
        :type circles: List[List[int]]
        :rtype: int
        """
        min_x = min(x-r for x, _, r in circles)
        max_x = max(x+r for x, _, r in circles)
        min_y = min(y-r for _, y, r in circles)
        max_y = max(y+r for _, y, r in circles)
        result = 0
        for i in xrange(min_x, max_x+1):
            for j in xrange(min_y, max_y+1):
                if any((i-x)**2+(j-y)**2 <= r**2 for x, y, r in circles):
                    result += 1
        return result
