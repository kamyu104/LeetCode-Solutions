# Time:  O(1)
# Space: O(1)

# simulation
class Solution(object):
    def trafficSignal(self, timer):
        """
        :type timer: int
        :rtype: str
        """
        if timer == 0:
            return "Green"
        elif timer == 30:
            return "Orange"
        elif 30 < timer <= 90:
            return "Red"
        return "Invalid"
