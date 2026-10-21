# Time:  ctor:         O(1)
#        toggle:       O(1)
#        getTotalTime: O(1)
#        getMinTime:   O(1)
# Space: O(n)

# hash table
class BusBooking(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self.__total = 0
        self.__lookup = {}

    def toggle(self, seat):
        """
        :type seat: str
        :rtype: None
        """
        if seat in self.__lookup:
            self.__total -= self.__lookup[seat]
            del self.__lookup[seat]
            return
        self.__lookup[seat] = 3 if (seat[0] == 'A' and 'B'+seat[1:] in self.__lookup) or (seat[0] == 'D' and 'C'+seat[1:] in self.__lookup) else 1
        self.__total += self.__lookup[seat]
        
    def getTotalTime(self):
        """
        :rtype: int
        """
        return self.__total

    def getMinTime(self):
        """
        :rtype: int
        """
        return len(self.__lookup)


# Time:  ctor:         O(n)
#        toggle:       O(1)
#        getTotalTime: O(1)
#        getMinTime:   O(1)
# Space: O(n)
# hash table
class BusBooking2(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self.__cnt = 0
        self.__total = 0
        self.__lookup = [[0]*n for _ in xrange(4)]

    def toggle(self, seat):
        """
        :type seat: str
        :rtype: None
        """
        i, j = ord(seat[0])-ord('A'), int(seat[1:])-1
        if self.__lookup[i][j]:
            self.__cnt -= 1
            self.__total -= self.__lookup[i][j]
            self.__lookup[i][j] = 0
            return
        self.__lookup[i][j] = 3 if (i == 0 and self.__lookup[i+1][j]) or (i == 3 and self.__lookup[i-1][j]) else 1
        self.__total += self.__lookup[i][j]
        self.__cnt += 1
        
    def getTotalTime(self):
        """
        :rtype: int
        """
        return self.__total

    def getMinTime(self):
        """
        :rtype: int
        """
        return self.__cnt
