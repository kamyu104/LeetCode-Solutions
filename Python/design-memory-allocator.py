# Time:  ctor:     O(1)
#        allocate: O(logn)
#        free:     O(logn)
# Space: O(n)

from sortedcontainers import SortedList
import collections

# sorted list
class Allocator(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self.__avails = SortedList([[0, n]])
        self.__lookup = collections.defaultdict(list)

    def allocate(self, size, mID):
        """
        :type size: int
        :type mID: int
        :rtype: int
        """
        for l, s in self.__avails:
            if s < size:
                continue
            self.__avails.remove([l, s])
            self.__lookup[mID].append([l, size])
            if s-size > 0:
                self.__avails.add([l+size, s-size])
            return l
        return -1

    def free(self, mID):
        """
        :type mID: int
        :rtype: int
        """
        if mID not in self.__lookup:
            return 0
        result = 0
        for l, s in self.__lookup[mID]:
            self.__avails.add([l, s])
            i = self.__avails.bisect_left([l, s])
            if i+1 < len(self.__avails) and self.__avails[i][0]+self.__avails[i][1] == self.__avails[i+1][0]:
                self.__avails[i][1] += self.__avails[i+1][1]
                del self.__avails[i+1]
            if i-1 >= 0 and self.__avails[i-1][0]+self.__avails[i-1][1] == self.__avails[i][0]:
                self.__avails[i-1][1] += self.__avails[i][1]
                del self.__avails[i]            
            result += s
        del self.__lookup[mID]
        return result
