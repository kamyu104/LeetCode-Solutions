# Time:  ctor:         O(nlogn)
#        changeRating: O(logn)
#        highestRated: O(1)
# Space: O(n)

import collections
import itertools
from sortedcontainers import SortedList


# sorted list
class FoodRatings(object):

    def __init__(self, foods, cuisines, ratings):
        """
        :type foods: List[str]
        :type cuisines: List[str]
        :type ratings: List[int]
        """
        self.__food_to_cuisine = {}
        self.__food_to_rating = {}
        self.__cusine_to_rating_foods = collections.defaultdict(SortedList)
        for food, cuisine, rating in itertools.izip(foods, cuisines, ratings):
            self.__food_to_cuisine[food] = cuisine
            self.__food_to_rating[food] = rating
            self.__cusine_to_rating_foods[cuisine].add((-rating, food))

    def changeRating(self, food, newRating):
        """
        :type food: str
        :type newRating: int
        :rtype: None
        """
        old_rating = self.__food_to_rating[food]
        cuisine = self.__food_to_cuisine[food]
        self.__cusine_to_rating_foods[cuisine].remove((-old_rating, food))
        self.__food_to_rating[food] = newRating
        self.__cusine_to_rating_foods[cuisine].add((-newRating, food))

    def highestRated(self, cuisine):
        """
        :type cuisine: str
        :rtype: str
        """
        return self.__cusine_to_rating_foods[cuisine][0][1]
