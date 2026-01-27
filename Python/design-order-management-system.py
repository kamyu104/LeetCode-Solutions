# Time:  ctor:             O(1)
#        addOrder:         O(1)
#        modifyOrder:      O(1)
#        cancelOrder:      O(1)
#        getOrdersAtPrice: O(n)
# Space: O(n)

import collections


# hash table
class OrderManagementSystem(object):

    def __init__(self):
        self.__orders = {}
        self.__type_price = collections.defaultdict(list)
        

    def addOrder(self, orderId, orderType, price):
        """
        :type orderId: int
        :type orderType: str
        :type price: int
        :rtype: None
        """
        self.__orders[orderId] = [orderType, price, len(self.__type_price[orderType, price])]
        self.__type_price[orderType, price].append(orderId)
        

    def modifyOrder(self, orderId, newPrice):
        """
        :type orderId: int
        :type newPrice: int
        :rtype: None
        """
        orderType = self.__orders[orderId][0]
        self.cancelOrder(orderId)
        self.addOrder(orderId, orderType, newPrice)
        

    def cancelOrder(self, orderId):
        """
        :type orderId: int
        :rtype: None
        """
        orderType, price, i = self.__orders[orderId]
        arr = self.__type_price[orderType, price]
        self.__orders[arr[-1]][2] = i
        arr[i], arr[-1] = arr[-1], arr[i]
        arr.pop()
        if not self.__type_price[orderType, price]:
            del self.__type_price[orderType, price]
        del self.__orders[orderId]


    def getOrdersAtPrice(self, orderType, price):
        """
        :type orderType: str
        :type price: int
        :rtype: List[int]
        """
        return self.__type_price.get((orderType, price), [])
  
