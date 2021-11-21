# Time:  O(n)
# Space: O(1)

class Solution(object):
    def wateringPlants(self, plants, capacity):
        """
        :type plants: List[int]
        :type capacity: int
        :rtype: int
        """
        result, can = len(plants), capacity
        for i, x in enumerate(plants):
            if can < x:
                result += 2*i
                can = capacity
            can -= x
        return result
