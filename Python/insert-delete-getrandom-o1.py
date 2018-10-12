# Time:  O(1)
# Space: O(n)

from random import randint

class RandomizedSet(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.__set = []
        self.__used = {}


    def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        if val in self.__used:
            return False

        self.__set += val,
        self.__used[val] = len(self.__set)-1

        return True


    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.__used:
            return False

        self.__used[self.__set[-1]] = self.__used[val]
        self.__set[self.__used[val]], self.__set[-1] = self.__set[-1], self.__set[self.__used[val]]

        self.__used.pop(val)
        self.__set.pop()

        return True

    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        return self.__set[randint(0, len(self.__set)-1)]



