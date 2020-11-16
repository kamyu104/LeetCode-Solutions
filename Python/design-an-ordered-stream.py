# Time:  O(1), amortized
# Space: O(n)

class OrderedStream(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self.__i = 0      
        self.__values = [None]*n

    def insert(self, id, value):
        """
        :type id: int
        :type value: str
        :rtype: List[str]
        """
        id -= 1
        self.__values[id] = value
        result = []
        if self.__i != id:
            return result
        while self.__i < len(self.__values) and self.__values[self.__i]:
            result.append(self.__values[self.__i])
            self.__i += 1
        return result
