# Time:  O(1)
# Space: O(1)

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


class Solution2(object):
    def isPowerOfThree(self, n):
        return n > 0 and (math.log10(n)/math.log10(3)).is_integer()

