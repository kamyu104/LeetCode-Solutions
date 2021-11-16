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

    def move(self, num):
        """
        :type num: int
        :rtype: None
        """
        self.__curr += num

    def getPos(self):
        """
        :rtype: List[int]
        """
        n = self.__curr % (2*((self.__w-1)+(self.__h-1)))
        if n < self.__w:
            return [n, 0]
        n -= self.__w-1
        if n < self.__h:
            return [self.__w-1, n]
        n -= self.__h-1
        if n < self.__w:
            return [(self.__w-1)-n, self.__h-1]
        n -= self.__w-1
        return [0, (self.__h-1)-n]

    def getDir(self):
        """
        :rtype: str
        """
        n = self.__curr % (2*((self.__w-1)+(self.__h-1)))
        if n < self.__w:
            return "South" if n == 0 and self.__curr else "East"
        n -= self.__w-1
        if n < self.__h:
            return "North"
        n -= self.__h-1
        if n < self.__w:
            return "West"
        n -= self.__w-1
        return "South"


# Time:  O(1)
# Space: O(1)
class Robot2(object):

    def __init__(self, width, height):
        """
        :type width: int
        :type height: int
        """
        self.__w = width
        self.__h = height
        self.__curr = 0

    def move(self, num):
        """
        :type num: int
        :rtype: None
        """
        self.__curr += num

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
        n = self.__curr % (2*((self.__w-1)+(self.__h-1)))
        if n < self.__w:
            return [[n, 0], "South" if n == 0 and self.__curr else "East"]
        n -= self.__w-1
        if n < self.__h:
            return [[self.__w-1, n], "North"]
        n -= self.__h-1
        if n < self.__w:
            return [[(self.__w-1)-n, self.__h-1], "West"]
        n -= self.__w-1
        return [[0, (self.__h-1)-n], "South"]
