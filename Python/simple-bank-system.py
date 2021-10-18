# Time:  ctor:     O(1)
#        transer:  O(1)
#        deposit:  O(1)
#        withdraw: O(1)
# Space: O(1)

class Bank(object):

    def __init__(self, balance):
        """
        :type balance: List[int]
        """
        self.__balance = balance

    def transfer(self, account1, account2, money):
        """
        :type account1: int
        :type account2: int
        :type money: int
        :rtype: bool
        """
        if 1 <= account2 <= len(self.__balance) and self.withdraw(account1, money):
            return self.deposit(account2, money)
        return False

    def deposit(self, account, money):
        """
        :type account: int
        :type money: int
        :rtype: bool
        """
        if 1 <= account <= len(self.__balance):
            self.__balance[account-1] += money
            return True
        return False

    def withdraw(self, account, money):
        """
        :type account: int
        :type money: int
        :rtype: bool
        """
        if 1 <= account <= len(self.__balance) and self.__balance[account-1] >= money:
            self.__balance[account-1] -= money
            return True
        return False
