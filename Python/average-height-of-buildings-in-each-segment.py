# Time:  O(nlogn)
# Space: O(n)

class Solution(object):
    def averageHeightOfBuildings(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        points = []
        for x, y, h in buildings:
            points.append((x, 1, h))
            points.append((y, -1, h))
        points.sort()
        result = []
        total = cnt = 0
        prev = -1
        for curr, c, h in points:
            if cnt and curr != prev:
                if result and result[-1][1] == prev and result[-1][2] == total//cnt:
                    result[-1][1] = curr
                else:
                    result.append([prev, curr, total//cnt])
            total += h*c
            cnt += c
            prev = curr
        return result


# Time:  O(nlogn)
# Space: O(n)
import collections


class Solution2(object):
    def averageHeightOfBuildings(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        count = collections.defaultdict(lambda: (0, 0))
        for x, y, h in buildings:
            count[x] = (count[x][0]+1, count[x][1]+h)
            count[y] = (count[y][0]-1, count[y][1]-h)
        result = []
        total = cnt = 0
        prev = -1
        for curr, (c, h) in sorted(count.iteritems()):
            if cnt:
                if result and result[-1][1] == prev and result[-1][2] == total//cnt:
                    result[-1][1] = curr
                else:
                    result.append([prev, curr, total//cnt])
            total += h
            cnt += c
            prev = curr
        return result
