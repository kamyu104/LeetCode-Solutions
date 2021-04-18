# Time:  O(n)
# Space: O(1)

class Solution(object):
    def badSensor(self, sensor1, sensor2):
        """
        :type sensor1: List[int]
        :type sensor2: List[int]
        :rtype: int
        """
        for i in xrange(len(sensor1)-1):
            if sensor1[i] == sensor2[i]:
                continue
            while i+1 < len(sensor2) and sensor2[i+1] == sensor1[i]:
                i += 1
            return 1 if i+1 == len(sensor2) else 2
        return -1
