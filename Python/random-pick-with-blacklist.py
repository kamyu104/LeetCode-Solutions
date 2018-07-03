# Time:  ctor: O(nlogn)
#        pick: O(logn)
# Space: O(n)

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

LEFT, RIGHT, ACCU_COUNT = range(3)


class Solution(object):

    def __init__(self, N, blacklist):
        """
        :type N: int
        :type blacklist: List[int]
        """
        self.__n = N-len(blacklist)
        self.__intervals = []
        blacklist.sort()
        prev, count = 0, 0
        for black in blacklist:
            if prev != black:
                self.__intervals.append((prev, black, count))
                count += black-prev
            prev = black+1
        self.__intervals.append((prev, N, count))

    def pick(self):
        """
        :rtype: int
        """
        index = random.randint(0, self.__n-1)
        left, right = 0, len(self.__intervals)-1
        while left <= right:
            mid = left+(right-left) // 2
            cur = self.__intervals[mid]
            if index < cur[ACCU_COUNT]+cur[RIGHT]-cur[LEFT]:
                right = mid-1
            else:
                left = mid+1
        return self.__intervals[left][LEFT] + \
            index - self.__intervals[left][ACCU_COUNT]


# Your Solution object will be instantiated and called as such:
# obj = Solution(N, blacklist)
# param_1 = obj.pick()
