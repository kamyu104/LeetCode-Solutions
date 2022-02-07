# Time:  ctor:     O(n)
#        fix:      O(1)
#        unfix:    O(1)
#        flip:     O(1)
#        all:      O(1)
#        one:      O(1)
#        count:    O(1)
#        toString: O(n)
# Space: O(n)

# design
class Bitset(object):

    def __init__(self, size):
        """
        :type size: int
        """
        self.__lookup = [False]*size
        self.__flip = False
        self.__cnt = 0

    def fix(self, idx):
        """
        :type idx: int
        :rtype: None
        """
        if self.__lookup[idx] == self.__flip:
            self.__lookup[idx] = not self.__lookup[idx]
            self.__cnt += 1
            
    def unfix(self, idx):
        """
        :type idx: int
        :rtype: None
        """
        if self.__lookup[idx] != self.__flip:
            self.__lookup[idx] = not self.__lookup[idx]
            self.__cnt -= 1

    def flip(self):
        """
        :rtype: None
        """
        self.__flip = not self.__flip
        self.__cnt = len(self.__lookup)-self.__cnt
        

    def all(self):
        """
        :rtype: bool
        """
        return self.__cnt == len(self.__lookup)

    def one(self):
        """
        :rtype: bool
        """
        return self.__cnt >= 1

    def count(self):
        """
        :rtype: int
        """
        return self.__cnt

    def toString(self):
        """
        :rtype: str
        """
        result = ['']*len(self.__lookup)
        for i, x in enumerate(self.__lookup):
            result[i] = '1' if x != self.__flip else '0'
        return "".join(result)
