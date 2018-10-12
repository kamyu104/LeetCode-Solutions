# Time:  O(nlogk)
# Space: O(k)

import heapq


class KthLargest(object):

    def __init__(self, k, nums):
        """
        :type k: int
        :type nums: List[int]
        """
        self.__k = k
        self.__min_heap = []
        for n in nums:
            self.add(n)
        

    def add(self, val):
        """
        :type val: int
        :rtype: int
        """
        heapq.heappush(self.__min_heap, val)
        if len(self.__min_heap) > self.__k:
            heapq.heappop(self.__min_heap)
        return self.__min_heap[0]



