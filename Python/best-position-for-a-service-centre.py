# Time:  O(n * iter), iter is the number of iterations
# Space: O(1)

# see reference:
# - https://en.wikipedia.org/wiki/Geometric_median
# - https://wikimedia.org/api/rest_v1/media/math/render/svg/b3fb215363358f12687100710caff0e86cd9d26b
# Weiszfeld's algorithm
class Solution(object):
    def getMinDistSum(self, positions):
        """
        :type positions: List[List[int]]
        :rtype: float
        """
        EPS = 1e-6
        def norm(p1, p2):
            return ((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)**0.5
        
        def geometry_median(positions, median):
            numerator, denominator = [0.0, 0.0], 0.0
            for p in positions:
                l = norm(median, p)
                if not l:
                    continue                       
                numerator[0] += p[0]/l
                numerator[1] += p[1]/l
                denominator += 1/l
            if denominator == 0.0:
                return True, None
            return False, [numerator[0]/denominator, numerator[1]/denominator]

        median = [float(sum(p[0] for p in positions))/len(positions),
                  float(sum(p[1] for p in positions))/len(positions)]
        prev_median = [float("-inf"), float("-inf")]
        while norm(median, prev_median)*len(positions) > EPS:
            stopped, new_median = geometry_median(positions, median)
            if stopped:
                break
            median, prev_median = new_median, median
        return sum(norm(median, p) for p in positions)


# Time:  O(n * iter), iter is the number of iterations
# Space: O(1)
class Solution2(object):
    def getMinDistSum(self, positions):
        """
        :type positions: List[List[int]]
        :rtype: float
        """
        DIRECTIONS = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        EPS = 1e-6
        def dist(positions, p):
            return sum(((p[0]-x)**2 + (p[1]-y)**2)**0.5 for x, y in positions)
        
        median = [0.0, 0.0]
        median[0] = float(sum(x for x, _ in positions))/len(positions)
        median[1] = float(sum(y for _, y in positions))/len(positions)
        result = dist(positions, median)
        delta = float(max(max(positions, key=lambda x: x[0])[0],
                          max(positions, key=lambda x: x[1])[1])) - \
                float(min(min(positions, key=lambda x: x[0])[0],
                          min(positions, key=lambda x: x[1])[1]))
        while delta > EPS:
            for dx, dy in DIRECTIONS:
                new_median = [median[0] + delta*dx, median[1] + delta*dy]
                nd = dist(positions, new_median)
                if nd < result: 
                    result = nd 
                    median = new_median
                    break 
            else:
                delta /= 2.0
        return result 
