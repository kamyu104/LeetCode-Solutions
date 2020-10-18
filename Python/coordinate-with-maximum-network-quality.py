# Time:  O(n^2)
# Space: O(1)

class Solution(object):
    def bestCoordinate(self, towers, radius):
        """
        :type towers: List[List[int]]
        :type radius: int
        :rtype: List[int]
        """
        min_x = min(towers, key=lambda x:x[0])[0]
        max_x = max(towers, key=lambda x:x[0])[0]
        min_y = min(towers, key=lambda x:x[1])[1]
        max_y = max(towers, key=lambda x:x[1])[1]
        max_quality = 0
        for x in xrange(min_x, max_x+1):
            for y in xrange(min_y, max_y+1):
                q = 0
                for nx, ny, nq in towers:
                    d = ((nx-x)**2+(ny-y)**2)**0.5
                    if d <= radius:
                        q += int(nq/(1+d))
                if q > max_quality:
                    max_quality = q
                    result = x, y
        return result
