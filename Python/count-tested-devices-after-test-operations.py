# Time:  O(n)
# Space: O(1)

# simulation
class Solution(object):
    def countTestedDevices(self, batteryPercentages):
        """
        :type batteryPercentages: List[int]
        :rtype: int
        """
        result = 0
        for x in batteryPercentages:
            if x > result:
                result += 1
        return result
