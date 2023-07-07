# Time:  O(k)
# Space: O(1)

# Definition for a street.
class Street:
    def closeDoor(self):
        pass
    def isDoorOpen(self):
        pass
    def moveRight(self):
        pass


# constructive algorithms
class Solution(object):
    def houseCount(self, street, k):
        """
        :type street: Street
        :type k: int
        :rtype: int
        """
        while not street.isDoorOpen():
            street.moveRight()
        result = 0
        for i in xrange(k+1):
            if i and street.isDoorOpen():
                street.closeDoor()
                result = i
            street.moveRight()
        return result
