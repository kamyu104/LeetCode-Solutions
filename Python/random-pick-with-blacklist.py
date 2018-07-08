# Time:  ctor: O(b)
#        pick: O(1)
# Space: O(b)

# Given a blacklist B containing unique integers from [0, N),
# write a function to return a uniform random integer from
# [0, N) which is NOT in B.
#
# Optimize it such that it minimizes the call to system’s Math.random().
#
# Note:
#
# 1 <= N <= 1000000000
# 0 <= B.length < min(100000, N)
# [0, N) does NOT include N. See interval notation.
# Example 1:
#
# Input:
# ["Solution","pick","pick","pick"]
# [[1,[]],[],[],[]]
# Output: [null,0,0,0]
# Example 2:
#
# Input:
# ["Solution","pick","pick","pick"]
# [[2,[]],[],[],[]]
# Output: [null,1,1,1]
# Example 3:
#
# Input:
# ["Solution","pick","pick","pick"]
# [[3,[1]],[],[],[]]
# Output: [null,0,0,2]
# Example 4:
#
# Input:
# ["Solution","pick","pick","pick"]
# [[4,[2]],[],[],[]]
# Output: [null,1,3,1]
# Explanation of Input Syntax:
#
# The input is two lists: the subroutines called and
# their arguments. Solution's constructor has two arguments,
# N and the blacklist B.
# pick has no arguments.
# Arguments are always wrapped with a list,
# even if there aren't any.

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


# Your Solution object will be instantiated and called as such:
# obj = Solution(N, blacklist)
# param_1 = obj.pick()
