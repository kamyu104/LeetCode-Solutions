# Time:  O(n)
# Space: O(n)

# Hash solution.
class Solution(object):
    def isReflected(self, points):
        """
        :type points: List[List[int]]
        :rtype: bool
        """
        if not points:
            return True
        groups_by_y = collections.defaultdict(set)
        left, right = float("inf"), float("-inf")
        for p in points:
            groups_by_y[p[1]].add(p[0])
            left, right = min(left, p[0]), max(right, p[0])
        mid = left + right
        for group in groups_by_y.values():
            for x in group:
                if mid - x not in group:
                    return False
        return True


# Time:  O(nlogn)
# Space: O(n)
# Two pointers solution.
class Solution2(object):
    def isReflected(self, points):
        """
        :type points: List[List[int]]
        :rtype: bool
        """
        if not points:
            return True
        points.sort()
        # Space: O(n)
        points[len(points)/2:] = sorted(points[len(points)/2:], \
                                        lambda x, y: y[1] - x[1] if x[0] == y[0] else \
                                                     x[0] - y[0])
        mid = points[0][0] + points[-1][0]
        left, right = 0, len(points) - 1
        while left <= right:
            if (mid != points[left][0] + points[right][0]) or \
               (points[left][0] != points[right][0] and \
                points[left][1] != points[right][1]):
                return False
            left += 1
            right -= 1
        return True
