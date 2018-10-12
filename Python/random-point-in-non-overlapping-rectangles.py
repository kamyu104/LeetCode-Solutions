# Time:  ctor: O(n)
#        pick: O(logn)
# Space: O(n)

import random
import bisect


class Solution(object):

    def __init__(self, rects):
        """
        :type rects: List[List[int]]
        """
        self.__rects = list(rects)
        self.__prefix_sum = map(lambda x : (x[2]-x[0]+1)*(x[3]-x[1]+1), rects)
        for i in xrange(1, len(self.__prefix_sum)):
            self.__prefix_sum[i] += self.__prefix_sum[i-1]

    def pick(self):
        """
        :rtype: List[int]
        """
        target = random.randint(0, self.__prefix_sum[-1]-1)
        left = bisect.bisect_right(self.__prefix_sum, target)
        rect = self.__rects[left]
        width, height = rect[2]-rect[0]+1, rect[3]-rect[1]+1
        base = self.__prefix_sum[left]-width*height
        return [rect[0]+(target-base)%width, rect[1]+(target-base)//width]



