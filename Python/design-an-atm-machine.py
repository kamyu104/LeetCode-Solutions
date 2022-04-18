# Time:  ctor:     O(1)
#        deposit:  O(1)
#        withdraw: O(1)
# Space: O(1)

# greedy
class ATM(object):

    def __init__(self):
        self.__vals = [20, 50, 100, 200, 500]
        self.__cnt = [0]*len(self.__vals)

    def deposit(self, banknotesCount):
        """
        :type banknotesCount: List[int]
        :rtype: None
        """
        for i, x in enumerate(banknotesCount):
            self.__cnt[i] += x

    def withdraw(self, amount):
        """
        :type amount: int
        :rtype: List[int]
        """
        result = [0]*len(self.__cnt)
        for i in reversed(xrange(len(self.__vals))):
            result[i] = min(amount//self.__vals[i], self.__cnt[i])
            amount -= result[i]*self.__vals[i]
        if amount:
            return [-1]
        for i, c in enumerate(result):
            self.__cnt[i] -= c
        return result
        
