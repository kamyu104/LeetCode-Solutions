# Time:  O(1)
# Space: O(1)

class Solution(object):
    def __init__(self):
        def dayOfMonth(M):
            return (28 if (M == 2) else 31-(M-1)%7%2)

        self.__lookup = [0]*12
        for M in xrange(1, len(self.__lookup)):
            self.__lookup[M] += self.__lookup[M-1]+dayOfMonth(M)

    def daysBetweenDates(self, date1, date2):
        """
        :type date1: str
        :type date2: str
        :rtype: int
        """
        def num_days(date):
            Y, M, D = map(int, date.split("-"))
            leap = 1 if M > 2 and (((Y % 4 == 0) and (Y % 100 != 0)) or (Y % 400 == 0)) else 0
            return (Y-1)*365 + ((Y-1)//4 - (Y-1)//100 + (Y-1)//400) + self.__lookup[M-1]+D+leap
     
        return abs(num_days(date1) - num_days(date2))


# Time:  O(1)
# Space: O(1)
import datetime


class Solution2(object):
    def daysBetweenDates(self, date1, date2):        
        delta = datetime.datetime.strptime(date1, "%Y-%m-%d")
        delta -= datetime.datetime.strptime(date2, "%Y-%m-%d")
        return abs(delta.days)
