# Time:  O(n)
# Space: O(n)

class Solution(object):
    def getCollisionTimes(self, cars):
        """
        :type cars: List[List[int]]
        :rtype: List[float]
        """
        stk = []
        result = [-1.0]*len(cars)
        for i in reversed(xrange(len(cars))):
            p, s = cars[i]
            while stk and (cars[stk[-1]][1] >= s or 
                           0 < result[stk[-1]] <= float(cars[stk[-1]][0]-p)/(s-cars[stk[-1]][1])):
                stk.pop()
            if stk:
                result[i] = float(cars[stk[-1]][0]-p)/(s-cars[stk[-1]][1])
            stk.append(i)
        return result
