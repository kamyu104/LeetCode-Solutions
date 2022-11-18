# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def convertTemperature(self, celsius):
        """
        :type celsius: float
        :rtype: List[float]
        """
        return [celsius+273.15, celsius*1.80+32.00]
