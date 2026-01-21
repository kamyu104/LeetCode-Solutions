# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def bestTower(self, towers, center, radius):
        """
        :type towers: List[List[int]]
        :type center: List[int]
        :type radius: int
        :rtype: List[int]
        """
        best = best_x = best_y = -1
        for x, y, q in towers:
            if not abs(x-center[0])+abs(y-center[1]) <= radius:
                continue
            if q > best:
                best, best_x, best_y = q, x, y
            elif q == best and (x < best_x or (x == best_x and y < best_y)):
                best_x, best_y = x, y
        return [best_x, best_y] if best != -1 else [-1, -1]


# Time:  O(n)
# Space: O(1)
# array
class Solution2(object):
    def bestTower(self, towers, center, radius):
        """
        :type towers: List[List[int]]
        :type center: List[int]
        :type radius: int
        :rtype: List[int]
        """
        result = [1]*3
        for x, y, q in towers:
            if not abs(x-center[0])+abs(y-center[1]) <= radius:
                continue
            result = min(result, [-q, x, y])
        return result[1:] if result[0] != 1 else [-1, -1]
