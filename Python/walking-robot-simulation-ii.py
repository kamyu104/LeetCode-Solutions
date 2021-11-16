# Time:  O(1)
# Space: O(1)

class Robot(object):

    def __init__(self, width, height):
        """
        :type width: int
        :type height: int
        """
        self.__w = width
        self.__h = height
        self.__curr = 0
        self.__moved = False

    def move(self, num):
        """
        :type num: int
        :rtype: None
        """
        if not self.__moved:
            self.__moved = True
        self.__curr = (self.__curr+num) % (2*((self.__w-1)+(self.__h-1)))

    def getPos(self):
        """
        :rtype: List[int]
        """
        return self.__getPosDir()[0] 

    def getDir(self):
        """
        :rtype: str
        """
        return self.__getPosDir()[1]

    def __getPosDir(self):
        n = self.__curr
        if n < self.__w:
            return [[n, 0], "South" if n == 0 and self.__moved else "East"]
        n -= self.__w-1
        if n < self.__h:
            return [[self.__w-1, n], "North"]
        n -= self.__h-1
        if n < self.__w:
            return [[(self.__w-1)-n, self.__h-1], "West"]
        n -= self.__w-1
        return [[0, (self.__h-1)-n], "South"]
