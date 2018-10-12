# Time:  seat:  O(logn) on average,
#        leave: O(logn)
# Space: O(n)

import heapq

LEN, POS, L, R = range(4)
LEFT, RIGHT = range(2)


class ExamRoom(object):

    def __init__(self, N):
        """
        :type N: int
        """
        self.__num = N
        self.__max_heap = [(-self.__num, 0, -1, self.__num)]
        self.__seats = {-1: [-1, self.__num],
                        self.__num: [-1, self.__num]}

    def seat(self):
        """
        :rtype: int
        """
        while self.__max_heap[0][L] not in self.__seats or \
                self.__max_heap[0][R] not in self.__seats or \
                self.__seats[self.__max_heap[0][L]][RIGHT] != \
                self.__max_heap[0][R] or \
                self.__seats[self.__max_heap[0][R]][LEFT] != \
                self.__max_heap[0][L]:
            heapq.heappop(self.__max_heap)  # lazy deletion

        curr = heapq.heappop(self.__max_heap)
        if curr[L] == -1 and curr[R] == self.__num:
            heapq.heappush(self.__max_heap, (-(curr[R]-1),
                                             curr[R]-1,
                                             curr[L]+1, curr[R]))
        elif curr[L] == -1:
            heapq.heappush(self.__max_heap, (-(curr[R]//2),
                                             curr[R]//2,
                                             curr[L]+1, curr[R]))
        elif curr[R] == self.__num:
            heapq.heappush(self.__max_heap, (-((curr[R]-1-curr[L])//2),
                                             (curr[R]-1-curr[L])//2+curr[L],
                                             curr[L], curr[R]-1))
        else:
            heapq.heappush(self.__max_heap, (-((curr[POS]-curr[L])//2),
                                             (curr[POS]-curr[L])//2+curr[L],
                                             curr[L], curr[POS]))
            heapq.heappush(self.__max_heap, (-((curr[R]-curr[POS])//2),
                                             (curr[R]-curr[POS])//2+curr[POS],
                                             curr[POS], curr[R]))
        self.__seats[curr[POS]] = [curr[L], curr[R]]
        self.__seats[curr[L]][RIGHT] = curr[POS]
        self.__seats[curr[R]][LEFT] = curr[POS]
        return curr[POS]

    def leave(self, p):
        """
        :type p: int
        :rtype: void
        """
        neighbors = self.__seats[p]
        self.__seats.pop(p)
        if neighbors[LEFT] == -1 and neighbors[RIGHT] == self.__num:
            heapq.heappush(self.__max_heap,
                           (-neighbors[RIGHT],
                            neighbors[LEFT]+1,
                            neighbors[LEFT], neighbors[RIGHT]))
        elif neighbors[LEFT] == -1:
            heapq.heappush(self.__max_heap,
                           (-neighbors[RIGHT],
                            neighbors[LEFT]+1,
                            neighbors[LEFT], neighbors[RIGHT]))
        elif neighbors[RIGHT] == self.__num:
            heapq.heappush(self.__max_heap,
                           (-(neighbors[RIGHT]-1-neighbors[LEFT]),
                            neighbors[RIGHT]-1,
                            neighbors[LEFT], neighbors[RIGHT]))
        else:
            heapq.heappush(self.__max_heap,
                           (-((neighbors[RIGHT]-neighbors[LEFT])//2),
                            (neighbors[RIGHT]-neighbors[LEFT])//2 +
                            neighbors[LEFT],
                            neighbors[LEFT], neighbors[RIGHT]))
        self.__seats[neighbors[LEFT]][RIGHT] = neighbors[RIGHT]
        self.__seats[neighbors[RIGHT]][LEFT] = neighbors[LEFT]



