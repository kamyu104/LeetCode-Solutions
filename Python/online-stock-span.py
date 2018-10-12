# Time:  O(n)
# Space: O(n)

class StockSpanner(object):

    def __init__(self):
        self.__s = []

    def next(self, price):
        """
        :type price: int
        :rtype: int
        """
        result = 1
        while self.__s and self.__s[-1][0] <= price:
            result += self.__s.pop()[1]
        self.__s.append([price, result])
        return result



