# Time:  ctor:             O(1)
#        addBid:           O(logn)
#        updateBid:        O(logn)
#        removeBid:        O(logn)
#        getHighestBidder: O(1), amortized
# Space: O(n)

import collections
import heapq


# hash table, heap
class AuctionSystem(object):

    def __init__(self):
        self.__bids = collections.defaultdict(lambda: collections.defaultdict(int))
        self.__bidders = collections.defaultdict(list)
        

    def addBid(self, userId, itemId, bidAmount):
        """
        :type userId: int
        :type itemId: int
        :type bidAmount: int
        :rtype: None
        """
        self.__bids[itemId][userId] = bidAmount
        heapq.heappush(self.__bidders[itemId], (-bidAmount, -userId))
        

    def updateBid(self, userId, itemId, newAmount):
        """
        :type userId: int
        :type itemId: int
        :type newAmount: int
        :rtype: None
        """
        self.addBid(userId, itemId, newAmount)


    def removeBid(self, userId, itemId):
        """
        :type userId: int
        :type itemId: int
        :rtype: None
        """
        del self.__bids[itemId][userId]
        if not self.__bids[itemId]:
            del self.__bids[itemId]


    def getHighestBidder(self, itemId):
        """
        :type itemId: int
        :rtype: int
        """
        if itemId not in self.__bidders:
            return -1
        while self.__bidders[itemId]:
            p, u = self.__bidders[itemId][0]
            p, u = -p, -u
            if self.__bids[itemId][u] == p:
                return u
            heapq.heappop(self.__bidders[itemId])
        del self.__bidders[itemId]
        return -1      


# Time:  ctor:             O(1)
#        addBid:           O(logn)
#        updateBid:        O(logn)
#        removeBid:        O(logn)
#        getHighestBidder: O(1)
# Space: O(n)
import collections
from sortedcontainers import SortedList


# hash table, sorted list
class AuctionSystem2(object):

    def __init__(self):
        self.__bids = collections.defaultdict(lambda: collections.defaultdict(int))
        self.__bidders = collections.defaultdict(SortedList)
        

    def addBid(self, userId, itemId, bidAmount):
        """
        :type userId: int
        :type itemId: int
        :type bidAmount: int
        :rtype: None
        """
        if userId in self.__bids[itemId]:
            self.__bidders[itemId].remove((self.__bids[itemId][userId], userId))
        self.__bids[itemId][userId] = bidAmount
        self.__bidders[itemId].add((bidAmount, userId))
        

    def updateBid(self, userId, itemId, newAmount):
        """
        :type userId: int
        :type itemId: int
        :type newAmount: int
        :rtype: None
        """
        self.addBid(userId, itemId, newAmount)


    def removeBid(self, userId, itemId):
        """
        :type userId: int
        :type itemId: int
        :rtype: None
        """
        self.__bidders[itemId].remove((self.__bids[itemId][userId], userId))
        if not self.__bidders[itemId]:
            del self.__bidders[itemId]
        del self.__bids[itemId][userId]
        if not self.__bids[itemId]:
            del self.__bids[itemId]


    def getHighestBidder(self, itemId):
        """
        :type itemId: int
        :rtype: int
        """
        return self.__bidders[itemId][-1][1] if itemId in self.__bidders else -1
        
