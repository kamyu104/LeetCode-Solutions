# Time:  seat:  O(logn), amortized
#        leave: O(logn)
# Space: O(n)

import heapq


class ExamRoom(object):

    def __init__(self, N):
        """
        :type N: int
        """
        self.__num = N
        self.__seats = {-1: [-1, self.__num], self.__num: [-1, self.__num]}
        self.__max_heap = [(-self.__distance((-1, self.__num)), -1, self.__num)]

    def seat(self):
        """
        :rtype: int
        """
        while self.__max_heap[0][1] not in self.__seats or \
              self.__max_heap[0][2] not in self.__seats or \
              self.__seats[self.__max_heap[0][1]][1] != self.__max_heap[0][2] or \
              self.__seats[self.__max_heap[0][2]][0] !=  self.__max_heap[0][1]:
            heapq.heappop(self.__max_heap)  # lazy deletion

        _, left, right = heapq.heappop(self.__max_heap)
        mid = 0 if left == -1 \
              else self.__num-1 if right == self.__num \
              else (left+right) // 2
        self.__seats[mid] = [left, right]
        heapq.heappush(self.__max_heap, (-self.__distance((left, mid)), left, mid))
        heapq.heappush(self.__max_heap, (-self.__distance((mid, right)), mid, right))
        self.__seats[left][1] = mid
        self.__seats[right][0] = mid
        return mid

    def leave(self, p):
        """
        :type p: int
        :rtype: void
        """
        left, right = self.__seats[p]
        self.__seats.pop(p)
        self.__seats[left][1] = right
        self.__seats[right][0] = left
        heapq.heappush(self.__max_heap, (-self.__distance((left, right)), left, right))
        
    def __distance(self, segment):
        return segment[1]-segment[0]-1 if segment[0] == -1 or segment[1] == self.__num \
               else (segment[1]-segment[0]) // 2

