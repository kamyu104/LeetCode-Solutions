# Time:  ctor:  O(n)
#        query: O(logn)
# Space: O(n)

import collections
import bisect


class RangeFreqQuery(object):

    def __init__(self, arr):
        """
        :type arr: List[int]
        """
        self.__idxs = collections.defaultdict(list)
        for i, x in enumerate(arr):
            self.__idxs[x].append(i)

    def query(self, left, right, value):
        """
        :type left: int
        :type right: int
        :type value: int
        :rtype: int
        """
        return bisect.bisect_right(self.__idxs[value], right) - \
               bisect.bisect_left(self.__idxs[value], left)
