# Time:  ctor:   O(nlogn)
#        search: O(logn)
#        rent:   O(logn)
#        drop:   O(logn)
#        report: O(logn)
# Space: O(n)

import collections
from sortedcontainers import SortedList


class MovieRentingSystem(object):

    def __init__(self, n, entries):
        """
        :type n: int
        :type entries: List[List[int]]
        """
        self.__movie_to_ordered_price_shop = collections.defaultdict(SortedList) 
        self.__shop_movie_to_price = {}
        self.__rented_ordered_price_shop_movie = SortedList()
        for s, m, p in entries:
            self.__movie_to_ordered_price_shop[m].add((p, s))
            self.__shop_movie_to_price[s, m] = p

    def search(self, movie):
        """
        :type movie: int
        :rtype: List[int]
        """
        return [s for _, s in self.__movie_to_ordered_price_shop[movie][:5]]

    def rent(self, shop, movie):
        """
        :type shop: int
        :type movie: int
        :rtype: None
        """
        price = self.__shop_movie_to_price[shop, movie]
        self.__movie_to_ordered_price_shop[movie].remove((price, shop))
        self.__rented_ordered_price_shop_movie.add((price, shop, movie))

    def drop(self, shop, movie):
        """
        :type shop: int
        :type movie: int
        :rtype: None
        """
        price = self.__shop_movie_to_price[shop, movie]
        self.__movie_to_ordered_price_shop[movie].add((price, shop))
        self.__rented_ordered_price_shop_movie.remove((price, shop, movie))

    def report(self):
        """
        :rtype: List[List[int]]
        """
        return [[s, m] for _, s, m in self.__rented_ordered_price_shop_movie[:5]]
