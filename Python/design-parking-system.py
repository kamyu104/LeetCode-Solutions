# Time:  O(1)
# Space: O(1)

class ParkingSystem(object):

    def __init__(self, big, medium, small):
        """
        :type big: int
        :type medium: int
        :type small: int
        """
        self.__space = [0, big, medium, small]

    def addCar(self, carType):
        """
        :type carType: int
        :rtype: bool
        """
        if self.__space[carType] > 0:
            self.__space[carType] -= 1
            return True
        return False
