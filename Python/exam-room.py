# Time:  seat:  O(logn) on average,
#        leave: O(logn)
# Space: O(n)

# In an exam room, there are N seats in a single row,
# numbered 0, 1, 2, ..., N-1.
#
# When a student enters the room,
# they must sit in the seat that maximizes the distance to the closest person.
# If there are multiple such seats, they sit in the seat with
# the lowest number.
# (Also, if no one is in the room, then the student sits at seat number 0.)
#
# Return a class ExamRoom(int N) that exposes two functions:
# ExamRoom.seat() returning an int representing what seat the student sat in,
# and ExamRoom.leave(int p) representing that the student in seat number p now
# leaves the room.
# It is guaranteed that any calls to ExamRoom.leave(p) have a student sitting
# in seat p.
#
# Example 1:
#
# Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"],
#        [[10],[],[],[],[],[4],[]]
# Output: [null,0,9,4,2,null,5]
# Explanation:
# ExamRoom(10) -> null
# seat() -> 0, no one is in the room, then the student sits at seat number 0.
# seat() -> 9, the student sits at the last seat number 9.
# seat() -> 4, the student sits at the last seat number 4.
# seat() -> 2, the student sits at the last seat number 2.
# leave(4) -> null
# seat() -> 5, the student sits at the last seat number 5.
#
# Note:
# - 1 <= N <= 10^9
# - ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times
#   across all test cases.
# - Calls to ExamRoom.leave(p) are guaranteed to have a student currently
#   sitting in seat number p.


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


# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(N)
# param_1 = obj.seat()
# obj.leave(p)
