# Time:  ctor:                   O(1)
#        addNumber:              O(logn)
#        removeFirstAddedNumber: O(logn)
#        getMean:                O(1)
#        getMedian:              O(1)
#        getMode:                O(1)
# Space: O(n)

# deque, freq table, sorted list
from sortedcontainers import SortedList
import collections


class StatisticsTracker(object):

    def __init__(self):
        self.__total = 0
        self.__dq = collections.deque()
        self.__sl1 = SortedList()
        self.__sl2 = SortedList()
        self.__num_to_freq = collections.defaultdict(int)
        self.__sorted_freqs = SortedList()
        self.__freq_to_nums = collections.defaultdict(SortedList)

    def __update(self, number, d):
        if number in self.__num_to_freq:
            self.__freq_to_nums[self.__num_to_freq[number]].remove(number)
            if not self.__freq_to_nums[self.__num_to_freq[number]]:
                del self.__freq_to_nums[self.__num_to_freq[number]]
                self.__sorted_freqs.remove(self.__num_to_freq[number]) 
        self.__num_to_freq[number] += d
        if not self.__num_to_freq[number]:
            del self.__num_to_freq[number]
        else:
            if not self.__freq_to_nums[self.__num_to_freq[number]]:
                self.__sorted_freqs.add(self.__num_to_freq[number])
            self.__freq_to_nums[self.__num_to_freq[number]].add(number)

    def __rebalance(self):
        if len(self.__sl2) == len(self.__sl1)+2:
            self.__sl1.add(self.__sl2.pop(0))
        elif len(self.__sl2)+1 == len(self.__sl1):
            self.__sl2.add(self.__sl1.pop(-1))
        
    def addNumber(self, number):
        """
        :type number: int
        :rtype: None
        """
        self.__total += number
        self.__dq.append(number)
        self.__update(number, +1)
        (self.__sl2 if not self.__sl2 or self.__sl2[0] <= number else self.__sl1).add(number)
        self.__rebalance()

    def removeFirstAddedNumber(self):
        """
        :rtype: None
        """
        number = self.__dq.popleft()
        self.__total -= number
        self.__update(number, -1)
        (self.__sl2 if number in self.__sl2 else self.__sl1).remove(number)
        self.__rebalance()

    def getMean(self):
        """
        :rtype: int
        """
        return self.__total//len(self.__dq)

    def getMedian(self):
        """
        :rtype: int
        """
        return self.__sl2[0]

    def getMode(self):
        """
        :rtype: int
        """
        return self.__freq_to_nums[self.__sorted_freqs[-1]][0]
