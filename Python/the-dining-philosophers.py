# Time:  O(n)
# Space: O(1)

import threading


class DiningPhilosophers(object):
    def __init__(self):
        self._l = [threading.Lock() for _ in xrange(5)]

    # call the functions directly to execute, for example, eat()
    def wantsToEat(self, philosopher, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork):
        """
        :type philosopher: int
        :type pickLeftFork: method
        :type pickRightFork: method
        :type eat: method
        :type putLeftFork: method
        :type putRightFork: method
        :rtype: void
        """
        left, right = philosopher, (philosopher+4)%5
        first, second = left, right
        if  philosopher%2 == 0:
            first, second = left, right
        else:
            first, second = right, left

        with self._l[first]:
            with self._l[second]:
                pickLeftFork()
                pickRightFork()
                eat()
                putLeftFork()
                putRightFork()
