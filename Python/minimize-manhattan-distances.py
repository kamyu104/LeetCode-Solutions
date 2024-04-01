# Time:  O(n)
# Space: O(1)

# math
class Solution(object):
    def minimumDistance(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        def max_distance(exclude):
            max_sum = max((x+y, i) for i, (x, y) in enumerate(points) if i != exclude)
            min_sum = min((x+y, i) for i, (x, y) in enumerate(points) if i != exclude)
            max_diff = max((x-y, i) for i, (x, y) in enumerate(points) if i != exclude)
            min_diff = min((x-y, i) for i, (x, y) in enumerate(points) if i != exclude)
            return max((max_sum[0]-min_sum[0], max_sum[1], min_sum[1]), 
                       (max_diff[0]-min_diff[0], max_diff[1], min_diff[1]))
        
        _, i, j = max_distance(-1)
        return min(max_distance(i)[0], max_distance(j)[0])
