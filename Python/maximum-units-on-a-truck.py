# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def maximumUnits(self, boxTypes, truckSize):
        """
        :type boxTypes: List[List[int]]
        :type truckSize: int
        :rtype: int
        """
        boxTypes.sort(key=lambda x: x[1], reverse=True)
        result = 0
        for box, units in boxTypes:
            if truckSize > box:
                truckSize -= box
                result += box*units
            else:
                result += truckSize*units
                break
        return result
