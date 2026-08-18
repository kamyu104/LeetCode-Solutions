# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def nearestDrone(self, drones, target):
        """
        :type drones: List[List[int]]
        :type target: List[int]
        :rtype: int
        """
        result, mn = -1, float("inf")
        for i in xrange(len(drones)):
            dist = abs(drones[i][0]-target[0])+abs(drones[i][1]-target[1])
            if dist > drones[i][2] or dist >= mn:
                continue
            result, mn = i, dist
        return result
