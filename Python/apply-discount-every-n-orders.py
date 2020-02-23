# Time:  ctor:    O(m), m is the number of all products
#        getBill: O(p), p is the number of products to bill
# Space: O(m)

class Cashier(object):

    def __init__(self, n, discount, products, prices):
        """
        :type n: int
        :type discount: int
        :type products: List[int]
        :type prices: List[int]
        """
        self.__n = n
        self.__discount = discount
        self.__curr = 0
        self.__lookup = {p : prices[i] for i, p in enumerate(products)}

    def getBill(self, product, amount):
        """
        :type product: List[int]
        :type amount: List[int]
        :rtype: float
        """
        self.__curr = (self.__curr+1) % self.__n
        result = 0.0
        for i, p in enumerate(product):
            result += self.__lookup[p]*amount[i]
        return result * (1.0 - self.__discount/100.0 if self.__curr == 0 else 1.0)    
