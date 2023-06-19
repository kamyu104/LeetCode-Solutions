# Time:  O(k)
# Space: O(1)

# Definition for a street.
class Street:
    def openDoor(self):
        pass
    def closeDoor(self):
        pass
    def isDoorOpen(self):
        pass
    def moveRight(self):
        pass
    def moveLeft(self):
        pass


# constructive algorithms
class Solution(object):
    def houseCount(self, street, k):
        """
        :type street: Street
        :type k: int
        :rtype: int
        """
        for _ in xrange(k):
            street.closeDoor()
            street.moveRight()
        for result in xrange(k+1):
            if street.isDoorOpen():
                break
            street.openDoor()
            street.moveRight()
        return result
