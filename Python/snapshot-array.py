# Time:  set: O(1)
#        get: O(logn), n is the total number of set
# Space: O(n)

import collections
import bisect


class SnapshotArray(object):

    def __init__(self, length):
        """
        :type length: int
        """
        self.__A = collections.defaultdict(lambda: [[0, 0]])
        self.__snap_id = 0


    def set(self, index, val):
        """
        :type index: int
        :type val: int
        :rtype: None
        """
        if self.__A[index][-1][0] == self.__snap_id:
            self.__A[index][-1][1] = val
        else:
            self.__A[index].append([self.__snap_id, val])


    def snap(self):
        """
        :rtype: int
        """
        self.__snap_id += 1
        return self.__snap_id - 1


    def get(self, index, snap_id):
        """
        :type index: int
        :type snap_id: int
        :rtype: int
        """
        i = bisect.bisect_left(self.__A[index], [snap_id+1, float("-inf")]) - 1
        return self.__A[index][i][1]   
