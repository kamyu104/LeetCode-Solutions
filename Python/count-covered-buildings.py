# Time:  O(n)
# Space: O(n)

# array
class Solution(object):
    def countCoveredBuildings(self, n, buildings):
        """
        :type n: int
        :type buildings: List[List[int]]
        :rtype: int
        """
        left = [n]*n
        right = [-1]*n
        up = [-1]*n
        down = [n]*n
        for x, y in buildings:
            x -= 1
            y -= 1
            left[y] = min(left[y], x)
            right[y] = max(right[y], x)
            up[x] = max(up[x], y)
            down[x] = min(down[x], y) 
        return sum(left[y-1] < x-1 < right[y-1] and down[x-1] < y-1 < up[x-1] for x, y in buildings)
