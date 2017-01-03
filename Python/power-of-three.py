# Time:  O(1)
# Space: O(1)

# Given an integer, write a function to determine
# if it is a power of three.
#
# Follow up:
# Could you do it without using any loop / recursion?
import math


class Solution(object):
    def __init__(self):
        self.__max_log3 = int(math.log(0x7fffffff) / math.log(3))
        self.__max_pow3 = 3 ** self.__max_log3

    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return n > 0 and self.__max_pow3 % n == 0
