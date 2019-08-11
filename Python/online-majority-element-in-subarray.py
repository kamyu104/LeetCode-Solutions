# Time:  ctor:  O(n)
#        query: O(klogn), k = log2(Q/ERROR_RATE)
# Space: O(n)

import collections
import random
import bisect


class MajorityChecker(object):

    def __init__(self, arr):
        """
        :type arr: List[int]
        """
        Q, ERROR_RATE = 10000, 0.001
        self.__k = int(Q/ERROR_RATE).bit_length()  # floor(log2(Q/ERROR_RATE))+1 = 24
        self.__arr = arr
        self.__inv_idx = collections.defaultdict(list)
        for i, x in enumerate(self.__arr):
            self.__inv_idx[x].append(i)

    def query(self, left, right, threshold):
        """
        :type left: int
        :type right: int
        :type threshold: int
        :rtype: int
        """
        for _ in xrange(self.__k):
            i = self.__arr[random.randint(left, right)]
            l = bisect.bisect_left(self.__inv_idx[i], left)
            r = bisect.bisect_right(self.__inv_idx[i], right)
            if r-l >= threshold:
                return i
        return -1

 
# Time:  ctor:  O(n)
#        query: O(nlogn)
# Space: O(n)
import collections
import bisect


class MajorityChecker2(object):

    def __init__(self, arr):
        """
        :type arr: List[int]
        """
        self.__arr = arr
        self.__inv_idx = collections.defaultdict(list)
        for i, x in enumerate(self.__arr):
            self.__inv_idx[x].append(i)

    def query(self, left, right, threshold):
        """
        :type left: int
        :type right: int
        :type threshold: int
        :rtype: int
        """
        for i, group in self.__inv_idx.iteritems():
            if len(group) < threshold:
                continue
            l = bisect.bisect_left(group, left)
            r = bisect.bisect_right(group, right)
            if r-l >= threshold:
                return i
        return -1
