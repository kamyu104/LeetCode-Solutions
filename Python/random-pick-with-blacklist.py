# Time:  ctor: O(b)
#        pick: O(1)
# Space: O(b)

import random


class Solution(object):
    
    def __init__(self, N, blacklist):
        """
        :type N: int
        :type blacklist: List[int]
        """
        self.__n = N-len(blacklist)
        self.__lookup = {}
        white = iter(set(range(self.__n, N))-set(blacklist))
        for black in blacklist:
            if black < self.__n:
                self.__lookup[black] = next(white)
        
        
    def pick(self):
        """
        :rtype: int
        """
        index = random.randint(0, self.__n-1)
        return self.__lookup[index] if index in self.__lookup else index


# Time:  ctor: O(blogb)
#        pick: O(logb)
# Space: O(b)
import random

class Solution2(object):
    
    def __init__(self, N, blacklist):
        """
        :type N: int
        :type blacklist: List[int]
        """
        self.__n = N-len(blacklist)
        blacklist.sort()
        self.__blacklist = blacklist
        
    def pick(self):
        """
        :rtype: int
        """
        index = random.randint(0, self.__n-1)
        left, right = 0, len(self.__blacklist)-1
        while left <= right:
            mid = left+(right-left)//2
            if index+mid < self.__blacklist[mid]:
                right = mid-1
            else:
                left = mid+1
        return index+left



