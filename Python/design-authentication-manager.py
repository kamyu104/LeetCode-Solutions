# Time:  ctor:     O(1)
#        generate: O(1), amortized
#        renew:    O(1), amortized
#        count:    O(1), amortized
# Space: O(n)

import collections


class AuthenticationManager(object):

    def __init__(self, timeToLive):
        """
        :type timeToLive: int
        """
        self.__time = timeToLive
        self.__lookup = collections.OrderedDict()

    def __evict(self, currentTime):
        while self.__lookup and next(self.__lookup.itervalues()) <= currentTime:
            self.__lookup.popitem(last=False)

    def generate(self, tokenId, currentTime):
        """
        :type tokenId: str
        :type currentTime: int
        :rtype: None
        """
        self.__evict(currentTime)
        self.__lookup[tokenId] = currentTime + self.__time


    def renew(self, tokenId, currentTime):
        """
        :type tokenId: str
        :type currentTime: int
        :rtype: None
        """
        self.__evict(currentTime)            
        if tokenId not in self.__lookup:
            return
        del self.__lookup[tokenId]
        self.__lookup[tokenId] = currentTime + self.__time

    def countUnexpiredTokens(self, currentTime):
        """
        :type currentTime: int
        :rtype: int
        """
        self.__evict(currentTime)
        return len(self.__lookup)
