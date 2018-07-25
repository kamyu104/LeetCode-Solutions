# Time:  O(1.189), counted by statistics, limit would be O(log10/log7) = O(1.183)
# Space: O(1)

# Given a function rand7 which generates a uniform random integer in the range 1 to 7,
# write a function rand10 which generates a uniform random integer in the range 1 to 10.
#
# Do NOT use system's Math.random().
#
# Example 1:
#
# Input: 1
# Output: [7]
# Example 2:
#
# Input: 2
# Output: [8,4]
# Example 3:
#
# Input: 3
# Output: [8,1,10]
#
# Note:
#
# rand7 is predefined.
# Each testcase has one argument: n, the number of times that rand10 is called.
#
# Follow up:
# - What is the expected value for the number of calls to rand7() function?
# - Could you minimize the number of calls to rand7()?
#
# The rand7() API is already defined for you.

import random


def rand7():
    return random.randint(1, 7)


# Reference: https://leetcode.com/problems/implement-rand10-using-rand7/discuss/151567/C++JavaPython-Average-1.199-Call-rand7-Per-rand10
class Solution(object):
    def __init__(self):
        self.__cache = []

    def rand10(self):
        """
        :rtype: int
        """
        def generate(cache):
            n = 32
            curr = sum((rand7()-1) * (7**i) for i in xrange(n))
            rang = 7**n
            while curr < rang//10*10:
                cache.append(curr%10+1)
                curr /= 10
                rang /= 10

        while not self.__cache:
            generate(self.__cache)
        return self.__cache.pop()


# Time:  O(2 * (1 + (9/49) + (9/49)^2 + ...)) = O(2/(1-(9/49)) = O(2.45)
# Space: O(1)
class Solution2(object):
    def rand10(self):
        """
        :rtype: int
        """
        while True:
            x = (rand7()-1)*7 + (rand7()-1)
            if x < 40:
                return x%10 + 1
